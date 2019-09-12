/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:07:46 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/12 15:50:04 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"

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
		, ex_command_zjmp, ex_command_ldi, ex_command_sti, 0};

	op_id = cur_process->vm.command.op.id;
	if (op_id == 12)
		ex_command_fork(mstr, cur_process, arena);
	else if (op_id && op_id <= 11)
		ex_command[op_id](cur_process, arena);
	cursor_next_op(cur_process);
	if (cur_process->vm.alive >= 1
		&& cur_process->vm.alive <= mstr->nb_of_players)
		{
			mstr->last_player_live = cur_process->vm.alive;
			mstr->live_signal++;
		}
	if (cur_process->vm.last_live == -1)
			mstr->live_signal++;
	cur_process->vm.alive = 0;
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
			run_command(mstr, cur_process, arena);
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
		cur_process->vm.wait--;
		cur_process->vm.last_live++;
		cur_process = cur_process->next;
	}
}

int			kill_processes(t_master *mstr, t_process **process)
{
	t_process *prev;
	t_process *cur;
	t_process *next;
	int test;

	prev = 0;
	cur = *process;
	next = cur->next;
	while (cur)
	{
		test = cur->vm.process_nb;
		if (cur->vm.last_live > mstr->foamy_bat_cycle)
		{
			printf("Cycle %d, death of process %d,last live %d,running processes %d\n",
			mstr->cur_cycle ,cur->vm.process_nb, cur->vm.last_live , mstr->running_processes - 1);
			ft_bzero(cur, sizeof(t_process));
			ft_memdel((void **)&cur);
			if (!prev)
				*process = next;
			else
				prev->next = next;
		}
		prev = cur ? cur : prev;
		cur = next;
		next = cur ? cur->next : next;
	}
	printf("amount of life signal %d and CTD : %d\n", mstr->live_signal, mstr->foamy_bat_cycle);
	if (++mstr->check == MAX_CHECKS || mstr->live_signal >= NBR_LIVE)
	{
		mstr->check = 0;
		mstr->foamy_bat_cycle -= CYCLE_DELTA;
	}
	mstr->live_signal = 0;
	return (mstr->foamy_bat_cycle);
}

void			war(t_master *mstr)
{
	int		ctd;

	ctd = mstr->foamy_bat_cycle;
	while (mstr->process)
	{
		++mstr->cur_cycle;
		ctd--;
		run_cycle(mstr);
		if (ctd <= 0)
			ctd = kill_processes(mstr, &mstr->process);
	}
}
