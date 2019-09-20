/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:07:46 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/20 20:18:10 by cizeur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"

/*
**		**************************************************
** **	Map initialised... now is the time for the COREWAR ** **
**		**************************************************
*/

void			run_command(t_master *mstr, t_process *cur_process, char *arena)
{
	int				op_id;
	static void		(*ex_command[AVAILABLE_OPERATIONS])() = {0,
		&ex_command_live, &ex_command_ld, &ex_command_st, &ex_command_add
		, &ex_command_sub, &ex_command_and, &ex_command_or, &ex_command_xor
		, ex_command_zjmp, ex_command_ldi, ex_command_sti, &ex_command_fork,
		&ex_command_lld, &ex_command_lldi, ex_command_lfork, &ex_command_aff};

	op_id = cur_process->vm.command.op.id;
	if (command_valid_types(cur_process->vm.command) == YES &&
		command_convert_param(cur_process, arena) == YES)
	{
		if (op_id && op_id < AVAILABLE_OPERATIONS)
			ex_command[op_id](mstr, cur_process, arena);
	}
	cursor_next_op(cur_process, mstr->options.verbose);
	cur_process->vm.alive = 0;
	ft_bzero(&(cur_process->vm.command), sizeof(t_command));
}

void			run_cycle(t_master *mstr)
{
	t_process	*cur_process;
	char		*arena;

	arena = mstr->arena;
	cur_process = mstr->process;
	while (cur_process)
	{
		if (cur_process->vm.wait == 1)
		{
			command_get_types(cur_process, cur_process->pc, arena);
			command_get_param(cur_process, arena);
			run_command(mstr, cur_process, arena);
		}
		else if (!cur_process->vm.wait)
		{
			if (command_get_info(cur_process, cur_process->pc, arena) == YES)
				;
			else
			{
				cur_process->vm.wait++;
				cur_process->pc++;
			}
		}
		cur_process->vm.wait--;
		cur_process->vm.last_live++;
		cur_process = cur_process->next;
	}
}



void			war(t_master *mstr)
{
	int		ctd;

	ctd = mstr->foamy_bat_cycle;
	while (mstr->process)
	{
		if (mstr->cur_cycle >= mstr->options.dump
			&& mstr->options.end_dump == N_DUMP)
			break ;
		++mstr->cur_cycle;
		if (mstr->options.verbose & VERBOSE_CYCL)
			ft_printf("Current Cycle %d \n", mstr->cur_cycle);
		ctd--;
		run_cycle(mstr);
		if (ctd <= 0)
			ctd = process_killing(mstr, &mstr->process);
	}
}
