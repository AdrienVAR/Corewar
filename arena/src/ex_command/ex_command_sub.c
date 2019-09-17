/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/17 19:10:02 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

static void			sub_verbose(t_process *process)
{
	t_command command;

	command = process->vm.command;

	printf("P - %5d | op : %s r%d - r%d =>> r%d ( %d - %d = %d)\n",
		process->vm.process_nb,
		command.op.name,
		command.param_conv[0].nb + 1,
		command.param_conv[1].nb + 1,
		command.param_conv[2].nb + 1,
		command.param_ext_conv[0].nb,
		command.param_ext_conv[1].nb,
		command.param_ext_conv[0].nb - command.param_ext_conv[1].nb);
}

void			ex_command_sub(t_master *mstr, t_process *process, char *arena)
{
	t_dir_cast	result;
	t_command	command;
	int			reg_dst;

	(void)mstr;
	(void)arena;
	command = process->vm.command;
	reg_dst = command.param_conv[2].nb;
	result.nb = command.param_ext_conv[0].nb - command.param_ext_conv[1].nb;
	sub_verbose(process);
	memrevcpy(process->registry[reg_dst], result.casted, DIR_SIZE);
	process->carry = !(result.nb) ? YES : NO;
}
