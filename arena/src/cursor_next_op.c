/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_next_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:41:18 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/17 18:05:12 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

static	void	cursor_verbose(int old_pc, int new_pc, int pcs_nb)
{
	printf("Cursor    : %#06x -> %#06x (P - %d)\n", old_pc, new_pc, pcs_nb);
}

void			cursor_next_op(t_process *process)
{
	int			i;
	int			pc;
	t_command	command;
	int			size;

	command = process->vm.command;
	process->pc = process->pc % MEM_SIZE;
	pc = process->pc;
	if (command.op.id == 9 && process->carry)
		return ;
	else if (!command.op.type_needed)
		pc += 1 + command.op.dir_size;
	else
	{
		pc += 2;
		i = -1;
		while (++i < command.op.nb_params)
		{
			size = command.types[i].size;
			size = command.types[i].type == T_DIR ?
				command.op.dir_size : size;
			pc += size;
		}
	}
	cursor_verbose(process->pc, pc % MEM_SIZE, process->vm.process_nb);
	process->pc = pc % MEM_SIZE;
}
