/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_st.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 09:32:10 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"

static void		st_verbose(t_process *process, int jump)
{
	t_command command;

	command = process->vm.command;
	if (command.types[1].type == T_REG)
		ft_printf("P - %5d | op : %s r%d[val = %d] => r%d\n",
		process->vm.process_nb,
		command.op.name,
		command.param_conv[0].nb + 1,
		command.param_ext_conv[0].nb,
		command.param_conv[1].nb + 1);
	else
		ft_printf("P - %5d | op : %s r%d[val = %d] =>  [ARENA] pc : %d\n",
		process->vm.process_nb,
		command.op.name,
		command.param_conv[0].nb + 1,
		command.param_ext_conv[0].nb,
		jump);
}

void			ex_command_st(t_master *mstr, t_process *process, char *arena)
{
	t_command	command;
	int			i;
	int			reg[2];
	int			jump;

	(void)mstr;
	(void)arena;
	command = process->vm.command;
	reg[0] = command.param_conv[0].nb;
	reg[1] = command.param_conv[1].nb;
	i = -1;
	jump = 0;
	if (command.types[1].type == T_IND)
	{
		jump = process->pc + command.param_conv[1].nb % IDX_MOD;
		while (++i < DIR_SIZE)
			arena_val_set(arena, process->registry[reg[0]][i], jump + i);
	}
	else if (command.types[1].type == T_REG)
	{
		while (++i < DIR_SIZE)
			process->registry[reg[1]][i] = process->registry[reg[0]][i];
	}
	if (mstr->options.verbose & VERBOSE_OPER)
		st_verbose(process, jump);
}
