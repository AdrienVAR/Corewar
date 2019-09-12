/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_ldi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/10 15:36:41 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

static			int elem_ind_dir(int pc, t_command command, char *arena)
{
	if (command.types[0].type == T_DIR)
		return (command.ind_val[0].nb);
	else
		return (command_extract_direct_value(arena,
			command.ind_val[0].nb, pc).nb);
}

static void		command_elem_ldi(t_process *process, t_command command, char *arena)
{
	t_dir_cast	elem[3];
	int			reg_dst;

	elem[0].nb = command.types[0].type == T_REG ?
		command_extract_register_value(process, command.reg_val[0].nb).nb :
		elem_ind_dir(process->pc, command, arena);
	elem[1].nb = command.types[1].type == T_REG ?
		command_extract_register_value(process, command.reg_val[1].nb).nb :
		command.ind_val[1].nb;
	reg_dst = command.reg_val[2].nb - 1;
	elem[2] = command_extract_direct_value(arena,
		(elem[0].nb + elem[1].nb) % IDX_MOD, process->pc);
	memrevcpy(process->registry[reg_dst], elem[2].casted, DIR_SIZE);
	process->carry = !(elem[2].nb) ? YES : NO;
}

void			ex_command_ldi(t_process *process, char *arena)
{
	t_command	command;

	command = process->vm.command;
	if (command_valid_types(command) == NO
		|| command_extract_register(&command) == NO)
		return ;
	command_extract_indirect(&command);
	command_elem_ldi(process, command, arena);
}
