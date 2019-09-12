/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:46:42 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/10 15:53:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

static			int elem_ind_dir(int pc, t_command command, char *arena)
{
	if (command.types[1].type == T_DIR)
		return (command.ind_val[1].nb);
	else
		return (command_extract_direct_value(arena,
			command.ind_val[1].nb, pc).nb);
}

static void		command_elem_sti(t_process *process, t_command command, char *arena)
{
	t_dir_cast	elem[3];
	int			i;
	int			jump;

	elem[0] = command_extract_register_value(process, command.reg_val[0].nb);
	elem[1].nb = command.types[1].type == T_REG ?
		command_extract_register_value(process, command.reg_val[1].nb).nb :
		elem_ind_dir(process->pc, command, arena);
	elem[2].nb = command.types[1].type == T_REG ?
		command_extract_register_value(process, command.reg_val[2].nb).nb :
		command.ind_val[2].nb;
	jump = (elem[1].nb + elem[2].nb) % IDX_MOD + process->pc;
	i = -1;
	while (++i < DIR_SIZE)
		arena[jump % MEM_SIZE + i] = elem[0].casted[DIR_SIZE - 1 - i];
}

void			ex_command_sti(t_process *process, char *arena)
{
	t_command	command;

	command = process->vm.command;
	if (command_valid_types(command) == NO
		|| command_extract_register(&command) == NO)
		return ;
	command_extract_indirect(&command);
	command_elem_sti(process, command, arena);
}
