/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_convert_param.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:52:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/19 17:04:12 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "utils.h"

int			command_extract_register(t_command *command, int p_ind)
{
	int				reg;
	t_reg_cast		reg_cast;

	if (command->types[p_ind].type != T_REG)
		return (YES);
	reg_cast.nb = 0;
	memrevcpy(reg_cast.casted,
		command->param[p_ind], REG_SIZE);
	reg = reg_cast.nb;
	if (!(reg >= 1 && reg <= REG_NUMBER))
		return (NO);
	command->param_conv[p_ind].nb = reg - 1;
	return (YES);
}

void		command_extract_indirect(t_process *process, int p_ind, t_arena *arena)
{
	t_ind_cast		ind_cast;
	t_dir_cast		ind_val;
	int				i;

	ind_cast.nb = 0;
	ind_val.nb = 0;
	if (process->vm.command.types[p_ind].type != T_IND)
		return ;
	memrevcpy(ind_cast.casted,
	process->vm.command.param[p_ind], IND_SIZE);
	if (process->vm.command.op.idx_mod)
		ind_cast.nb %= IDX_MOD;
	process->vm.command.param_conv[p_ind].nb = ind_cast.nb;
	process->vm.command.param_ext_conv[p_ind].nb = 0;
	i = -1;
	while (++i < DIR_SIZE)
		ind_val.casted[DIR_SIZE - 1 - i] =
			arena_val_get(arena, ind_cast.nb + process->pc + i);
	process->vm.command.param_ext_conv[p_ind].nb = ind_val.nb;
}

void		command_extract_direct(t_command *command, int p_ind)
{
	t_ind_cast		ind_cast;
	t_dir_cast		dir_cast;

	ind_cast.nb = 0;
	dir_cast.nb = 0;
	if (command->types[p_ind].type != T_DIR)
		return ;
	if (command->op.dir_size == IND_SIZE)
	{
		memrevcpy(ind_cast.casted,
		command->param[p_ind], IND_SIZE);
		command->param_conv[p_ind].nb = ind_cast.nb;
	}
	else
	{
		memrevcpy(dir_cast.casted,
		command->param[p_ind], DIR_SIZE);
		command->param_conv[p_ind].nb = dir_cast.nb;
	}
}

void		command_extract_register_value(t_process *process, int p_ind)
{
	t_dir_cast		reg;
	int				reg_n;

	if (process->vm.command.types[p_ind].type != T_REG)
		return ;
	reg.nb = 0;
	reg_n = process->vm.command.param_conv[p_ind].nb;
	memrevcpy(reg.casted, process->registry[reg_n], DIR_SIZE);
	process->vm.command.param_ext_conv[p_ind].nb = reg.nb;
}

int			command_convert_param(t_process *process, t_arena *arena)
{
	int			i;
	int			type;
	t_command	*command;

	i = -1;
	command = &(process->vm.command);
	while (++i < command->op.nb_params)
	{
		type = command->types[i].type;
		type += command->types[i].type == T_DIR &&
			command->op.dir_size == IND_SIZE ? T_IND : 0;
		if (command_extract_register(command, i) == NO)
			return (NO);
		else
			command_extract_register_value(process, i);
		command_extract_direct(command, i);
		command_extract_indirect(process, i, arena);
	}
	return (YES);
}
