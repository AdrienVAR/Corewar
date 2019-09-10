/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_next_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:41:18 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/10 09:30:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void		cursor_next_op(t_process *process)
{
	int 		i;
	int			pc;
	t_command	command;

	command = process->vm.command;
	pc = process->pc;
	if(command.op.id == 9)
		return ;
	else if (!command.op.type_needed)
		pc += 1 + DIR_SIZE;
	else
	{
		pc += 2;
		i = -1;
		while (++i < command.op.nb_params)
			pc += command.types[i].size;
	}
	process->pc = pc % MEM_SIZE;
}
