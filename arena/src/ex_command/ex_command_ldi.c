/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_ldi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/14 15:45:39 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_ldi(t_master *mstr, t_process *process, char *arena)
{
	t_command	command;
	t_dir_cast	elem[3];
	t_dir_cast	dest_val;
	int			jump;
	int			i;

	(void)mstr;
	command = process->vm.command;
	elem[0] = command.types[0].type != T_DIR ?
	command.param_ext_conv[0] : command.param_conv[0];
	elem[1] = command.types[1].type != T_DIR ?
	command.param_ext_conv[1] : command.param_conv[1];
	elem[2] = command.param_conv[2];
	jump = (elem[0].nb + elem[1].nb) % IDX_MOD + process->pc;
	i = -1;
	while (++i < DIR_SIZE)
		dest_val.casted[DIR_SIZE - i - 1] =
			arena_val_get(arena, jump + i);
	memrevcpy(process->registry[elem[2].nb], dest_val.casted, DIR_SIZE);
	process->carry = dest_val.nb ? YES : NO;
}
