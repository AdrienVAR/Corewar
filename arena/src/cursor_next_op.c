/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_next_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesargironvm <cesargironvm@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:41:18 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/07 18:31:29 by cesargironv      ###   ########.fr       */
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
	if (!command.op.type_needed)
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
