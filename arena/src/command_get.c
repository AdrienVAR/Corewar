/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:31:12 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/10 14:58:03 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void		command_get_types(t_process *cur_process, t_uchar type_code)
{
	int			i;
	t_uchar		type;

	i = MAX_ARGS_NUMBER;
	while (--i >= 0)
	{
		type = type_code & 3;
		type_code >>= 2;
		cur_process->vm.command.types[i] = type_val((int)type);
	}
}

int			command_get_info(t_process *cur_process, t_uchar op_code)
{
	t_op			operation;

	operation = operation_get_info(op_code);
	if (!operation.id)
		return (NO);
	cur_process->vm.command.op = operation;
	cur_process->vm.wait = operation.duration;
	return (YES);
}

void		command_get_param(t_process *cur_process, char *arena)
{
	t_command		command;
	int				pc;
	int				i;
	int				j;
	int				size;

	i = -1;
	pc = (cur_process->pc + 2) % MEM_SIZE;
	command = cur_process->vm.command;
	while (++i < command.op.nb_params)
	{
		j = -1;
		size = command.types[i].size;
		size = command.types[i].type == T_DIR?
			command.op.dir_size : size;
		while (++j < size)
			command.param[i][j] = arena_val(arena, pc++);
	}
	cur_process->vm.command = command;
}
