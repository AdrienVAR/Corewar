/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_zjmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:34:21 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"

static void			zjmp_verbose(t_process *process, int carry)
{
	ft_printf("P - %5d | op : %5s %d (%d -> %d) : %s\n",
		process->vm.process_nb,
		process->vm.command.op.name,
		process->vm.command.param_conv[0].nb,
		process->pc,
		process->pc + process->vm.command.param_conv[0].nb % IDX_MOD,
		carry ? "SUCCESS" : "FAILURE");
}

void			ex_command_zjmp(t_master *mstr, t_process *process, char *arena)
{
	(void)mstr;
	(void)arena;
	zjmp_verbose(process, process->carry);
	if (process->carry == NO)
		return ;
	process->pc = process->pc + process->vm.command.param_conv[0].nb % IDX_MOD;
}
