/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_ld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 13:45:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"
#include "utils.h"

static void	ld_verbose(t_process *process)
{
	t_command command;

	command = process->vm.command;
	if (command.types[0].type == T_IND)
		ft_printf("P - %5d | op : %s [IND %d = %d] =>  r%d\n",
		process->vm.process_nb,
		command.op.name,
		command.param_conv[0].nb,
		command.param_ext_conv[0].nb,
		command.param_conv[1].nb + 1);
	else
		ft_printf("P - %5d | op : %s %d =>  r%d\n",
		process->vm.process_nb,
		command.op.name,
		command.param_conv[0].nb,
		command.param_conv[1].nb + 1);
}

void		ex_command_ld(t_master *mstr, t_process *process, t_arena *arena)
{
	t_command	command;
	t_dir_cast	load_val;

	(void)mstr;
	(void)arena;
	command = process->vm.command;
	load_val = command.types[0].type == T_IND ?
			command.param_ext_conv[0] : command.param_conv[0];
	memrevcpy(process->registry[command.param_conv[1].nb],
		load_val.casted, DIR_SIZE);
	process->carry = !load_val.nb ? YES : NO;
	if (mstr->options.verbose & VERBOSE_OPER)
		ld_verbose(process);
}
