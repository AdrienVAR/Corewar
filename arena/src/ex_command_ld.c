/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_ld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/05 15:59:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_ld(t_process *process, char *arena)
{
	t_command command;

	int i;
	int reg;
	int pc;

	command = process->vm.command;
	pc = command.op.type_needed ? process->pc + 2 : process->pc + 1;
	if (command_valid_types(command) == NO
		|| (reg = command_valid_register(command, 1)) == NO)
		return ;
	i = -1;
	while (++i < DIR_SIZE)
		process->registry[reg][i] = arena_val(arena, pc + i);
	printf("RUUUUUN COMMAND RUUUUUUUN !!!\n");
}
