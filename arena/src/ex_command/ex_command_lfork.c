/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_lfork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 19:19:10 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"

static void	lfork_verbose(t_process *process, t_process *new)
{
	ft_printf("P - %5d | op : %5s %d (%d -> %d) => [P - %5d]\n",
		process->vm.process_nb,
		process->vm.command.op.name,
		process->vm.command.param_conv[0].nb,
		process->pc,
		new->pc,
		new->vm.process_nb);
}

static void	born_verbose(t_process *new, t_master *mstr)
{
	ft_printf("P - %5d is BORN at PC : %5d [ A: %d / T :%d ]\n",
		new->vm.process_nb,
		new->pc,
		mstr->active_processes,
		mstr->total_processes);
}

void		ex_command_lfork(t_master *mstr, t_process *process, char *arena)
{
	t_process	*new_process;

	(void)arena;
	if (!(new_process = (t_process *)ft_memalloc(sizeof(t_process))))
		exit_program(mstr);
	new_process->carry = process->carry;
	new_process->pc = (process->pc +
		process->vm.command.param_conv[0].nb) % MEM_SIZE;
	ft_memcpy(new_process->registry,
		process->registry, sizeof(process->registry));
	new_process->next = mstr->process;
	new_process->vm.last_live = process->vm.last_live + 1;
	new_process->vm.process_nb = ++mstr->total_processes;
	new_process->vm.player = process->vm.player;
	++mstr->active_processes;
	mstr->process = new_process;
	if (mstr->options.verbose & VERBOSE_OPER)
		lfork_verbose(process, new_process);
	if (mstr->options.verbose & VERBOSE_BORN)
		born_verbose(new_process, mstr);
}
