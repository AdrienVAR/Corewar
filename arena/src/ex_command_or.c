/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/09 15:30:51 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

static void		command_comp_or(t_process *process, t_command command, char *arena)
{
	t_dir_cast	comp[3];
	int			reg_dst;
	int			dec;

	dec = command.types[0].type == T_IND ? command.ind_val[0].nb % IDX_MOD : 2;
	comp[0] = command.types[0].type == T_REG ?
	command_extract_register_value(process, command.reg_val[0].nb) :
	command_extract_direct_value(arena, dec, process->pc);
	dec = command.types[1].type == T_IND ?
		command.ind_val[1].nb % IDX_MOD : 2 + command.types[0].size;
	comp[1] = command.types[1].type == T_REG ?
	command_extract_register_value(process, command.reg_val[1].nb) :
	command_extract_direct_value(arena, dec, process->pc);
	reg_dst = command.reg_val[2].nb - 1;
	comp[2].nb = comp[0].nb | comp[1].nb;
	memrevcpy(process->registry[reg_dst], comp[2].casted, DIR_SIZE);
	if (!(comp[2].nb))
		process->carry = 1;
}

void			ex_command_or(t_process *process, char *arena)
{
	t_command	command;

	command = process->vm.command;
	if (command_valid_types(command) == NO
		|| command_extract_register(&command) == NO)
		return ;
	command_extract_indirect(&command);
	command_comp_or(process, command, arena);
}
