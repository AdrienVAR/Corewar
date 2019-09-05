/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_next_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:41:18 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/05 18:28:34 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void		cursor_next_op(t_process *process)
{
	int i;
	int pc;
	t_command command;

	command = process->vm.command;
	pc = process->pc;
	pc += command.op.type_needed ? 2 : 1;
	i = -1;
	while (++i < command.op.nb_params)
		pc += command.types[i].size;
	process->pc = pc % MEM_SIZE;
}
