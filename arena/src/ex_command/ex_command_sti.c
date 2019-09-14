/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:46:42 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/14 15:04:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_sti(t_master *mstr, t_process *process, char *arena)
{
	t_command	command;
	t_dir_cast	src;
	t_dir_cast	elem[2];
	int			jump;
	int			i;

	(void)mstr;
	(void)arena;
	command = process->vm.command;
	src = command.param_ext_conv[0];
	elem[0] = command.types[1].type != T_DIR ?
	command.param_ext_conv[1] : command.param_conv[1];
	elem[1] = command.types[2].type != T_DIR ?
	command.param_ext_conv[2] : command.param_conv[2];
	jump = (elem[0].nb + elem[1].nb) % IDX_MOD + process->pc;
	i = -1;
	while (++i < DIR_SIZE)
		arena_val_set(arena, src.casted[DIR_SIZE - 1 - i],
			jump + i);
}
