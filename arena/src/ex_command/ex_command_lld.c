/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_lld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/14 19:30:20 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_lld(t_master *mstr, t_process *process, char *arena)
{
	t_command	command;
	t_dir_cast	load_val;
	t_ind_cast	ind_case;
	int 		i;

	(void)mstr;
	(void)arena;
	command = process->vm.command;
	i = -1;
	while (++i < IND_SIZE)
		ind_case.casted[i] =
			(command.param_ext_conv[0].casted[DIR_SIZE - IND_SIZE + i]);
	load_val.nb = command.types[0].type == T_IND ?
		ind_case.nb : command.param_conv[0].nb;
	memrevcpy(process->registry[command.param_conv[1].nb],
		load_val.casted, DIR_SIZE);
	process->carry = !load_val.nb ? YES : NO;
}
