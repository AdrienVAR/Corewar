/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/09 17:35:09 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

static void		command_reg_add(t_process *process, t_command command)
{
	t_dir_cast	reg[3];
	int			reg_dst;
	int			i;

	reg[0] = command_extract_register_value(process, command.reg_val[0].nb);
	reg[1] = command_extract_register_value(process, command.reg_val[1].nb);
	reg_dst = command.reg_val[2].nb - 1;
	reg[2].nb = reg[0].nb + reg[1].nb;
	i = -1;
	while (++i < DIR_SIZE)
		process->registry[reg_dst][DIR_SIZE - 1 - i] = reg[2].casted[i];
	process->carry = !(reg[2].nb) ? YES : NO;
}

void			ex_command_add(t_process *process)
{
	t_command	command;

	command = process->vm.command;
	if (command_valid_types(command) == NO
		|| command_extract_register(&command) == NO)
		return ;
	command_reg_add(process, command);
}
