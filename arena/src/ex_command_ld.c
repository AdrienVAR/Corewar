/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_ld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/06 12:13:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_ld(t_process *process, char *arena)
{
	t_command command;

	int i;
	int reg;
	int jump;

	command = process->vm.command;
	jump = command.op.type_needed ? 2 : 1;
	if (command_valid_types(command) == NO
		|| command_extract_register(&command) == NO)
		return ;
	command_extract_indirect(&command);
	reg = command.reg_val[1].nb;
	if (command.types[0].type == T_IND)
		jump = command.ind_val[0].nb ;
	jump %= IDX_MOD;
	i = -1;
	while (++i < DIR_SIZE)
		process->registry[reg][i] = arena_val(arena, process->pc + i + jump);
	printf("RUUUUUN COMMAND RUUUUUUUN !!!\n");
}
