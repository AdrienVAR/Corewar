/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_ld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/14 15:47:08 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_ld(t_master *mstr, t_process *process, char *arena)
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
}
