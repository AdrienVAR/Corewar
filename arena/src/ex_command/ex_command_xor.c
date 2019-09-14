/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_xor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:18:04 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/14 15:06:55 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_xor(t_master *mstr, t_process *process, char *arena)
{
	t_dir_cast	comp[3];
	int			reg_dst;
	t_command	command;

	(void)mstr;
	(void)arena;
	command = process->vm.command;
	comp[0] = command.types[0].type != T_DIR ?
	command.param_ext_conv[0] : command.param_conv[0];
	comp[1] = command.types[1].type != T_DIR ?
	command.param_ext_conv[1] : command.param_conv[1];
	reg_dst = command.param_conv[2].nb;
	comp[2].nb = comp[0].nb ^ comp[1].nb;
	memrevcpy(process->registry[reg_dst], comp[2].casted, DIR_SIZE);
	process->carry = !(comp[2].nb) ? YES : NO;
}
