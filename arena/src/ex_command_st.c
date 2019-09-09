/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_st.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesargironvm <cesargironvm@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/07 18:29:24 by cesargironv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_st(t_process *process, char *arena)
{
	t_command	command;
	int			i;
	int			reg[2];
	int			jump;

	command = process->vm.command;
	if (command_valid_types(command) == NO
		|| command_extract_register(&command) == NO)
		return ;
	command_extract_indirect(&command);
	reg[0] = command.reg_val[0].nb - 1;
	reg[1] = command.reg_val[1].nb - 1;
	i = -1;
	if (command.types[1].type == T_IND)
	{
		jump = command.ind_val[1].nb;
		jump %= IDX_MOD;
		while (++i < DIR_SIZE)
			arena[(process->pc + jump + i) % MEM_SIZE] = process->registry[reg[0]][i];
	}
	else if (command.types[1].type == T_REG)
	{
		while (++i < DIR_SIZE)
			process->registry[reg[1]][i] = process->registry[reg[0]][i];
	}
}
