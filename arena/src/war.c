/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:07:46 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/04 19:05:22 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"

/*
**		**************************************************
** **	Map initialised... now is the time for the COREWAR ** **
**		**************************************************
*/

void			run_command(t_process *cur_process, char *arena)
{
	static void		(*command_functions[AVAILABLE_OPERATIONS])()=
	{};

	command_functions[0] = 0;
	cur_process = 0;
	arena = 0;
	ft_putstr("RUUUUUN COMMAND RUUUUUUUN !!!\n");
}

void			command_get_types_size(t_process *cur_process)
{
	int i;
	int type;
	int type_size;

	i = -1;
	while (++i < MAX_ARGS_NUMBER)
	{
		type_size = 0;
		type = 0;
		type = cur_process->vm.command.types[i];
		type_size = type == DIR_CODE ? DIR_SIZE : type_size;
		type_size = type == REG_CODE ? REG_SIZE : type_size;
		type_size = type == IND_CODE ? IND_SIZE : type_size;
		cur_process->vm.command.types_size[i] = type_size;
	}
}

void			command_get_types(t_process *cur_process, uchar type_code)
{
	int i;
	char type;

	i = MAX_ARGS_NUMBER;
	while (--i >= 0)
	{
		type = type_code & 3;
		type_code >>= 2;
		cur_process->vm.command.types[i] = (int)type;
	}
}

void			command_get_info(t_process *cur_process, uchar op_code)
{
	t_op operation;
	t_vm_pcs_track vm;

	operation = operation_get_info(op_code);
	vm = cur_process->vm;
	vm.command.op = operation;
	vm.wait = operation.duration;
	cur_process->vm = vm;
}


void			command_get_param(t_process *cur_process, char *arena)
{
	t_command		command;
	int				pc;
	int				i;
	int				j;

	i = -1;
	pc = (cur_process->pc + 2) % MEM_SIZE;
	command = cur_process->vm.command;
	while (++i < command.op.nb_params)
	{
		j = -1;
		while (++j < command.types_size[i])
			(command.param)[j][i] = arena_val(arena, pc++);
	}
	cur_process->vm.command = command;
}


void			run_cycle(t_master *mstr)
{
	t_process	*cur_process;
	char		*arena;

	arena = mstr->arena;
	cur_process = mstr->process;
	while (cur_process)
	{
		if (cur_process->vm.wait == 1)
			run_command(cur_process, arena);
		else if (!cur_process->vm.wait)
		{
			command_get_info(cur_process, arena_val(arena, cur_process->pc));
			command_get_types(cur_process, arena_val(arena, cur_process->pc + 1));
			command_get_types_size(cur_process);
			command_get_param(cur_process, arena);
		}
		cur_process->vm.wait--;
		cur_process = cur_process->next;
	}
}

void			war(t_master *mstr)
{

	while (mstr->cur_cycle < 15)
	{
		++mstr->cur_cycle;
		run_cycle(mstr);
	}
}
