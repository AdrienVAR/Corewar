/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/14 15:07:00 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

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
	memrevcpy(process->registry[reg_dst], result.casted, DIR_SIZE);
	process->carry = !(result.nb) ? YES : NO;
}
