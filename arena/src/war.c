/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:07:46 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/06 16:18:40 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"

/*
**		**************************************************
** **	Map initialised... now is the time for the COREWAR ** **
**		**************************************************
*/

void			run_command(t_process *cur_process, char *arena)
{
	int				op_id;
	static void		(*ex_command[AVAILABLE_OPERATIONS])() = {0,
		&ex_command_live, &ex_command_ld};

	op_id = cur_process->vm.command.op.id;
	if (op_id && op_id <= 2)
	{
		ex_command[op_id](cur_process, arena);
	}
	cursor_next_op(cur_process);
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
			run_command(cur_process, arena);
		else if (!cur_process->vm.wait)
		{
			if (command_get_info(cur_process, arena_val(arena, cur_process->pc)) == YES)
			{
				command_get_types(cur_process, arena_val(arena, cur_process->pc + 1));
				command_get_param(cur_process, arena);
			}
			else
			{
				cur_process->vm.wait++;
				cur_process->pc++;
			}
		}
		if (cur_process->vm.alive >= 1
				&& cur_process->vm.alive <= mstr->nb_of_players)
			mstr->last_player_live = cur_process->vm.alive;
		cur_process->vm.alive = 0;
		cur_process->vm.wait--;
		cur_process->vm.last_live++;
		cur_process = cur_process->next;
	}
}

void			war(t_master *mstr)
{

	while (mstr->cur_cycle < 5000)
	{
		++mstr->cur_cycle;
		run_cycle(mstr);
	}
}
