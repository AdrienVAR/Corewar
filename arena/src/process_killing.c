/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_killing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:04:34 by cizeur            #+#    #+#             */
/*   Updated: 2019/09/20 20:37:36 by cizeur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"

static void	update_life_check(t_master *mstr)
{
	if (++mstr->check == MAX_CHECKS || mstr->live_signal >= NBR_LIVE)
	{
		mstr->check = 0;
		mstr->foamy_bat_cycle -= CYCLE_DELTA;
	}
	mstr->live_signal = 0;
}

static void	verbose_life_check(t_master *mstr, t_process *cur)
{
			--mstr->active_processes;
			if (!(mstr->options.verbose & VERBOSE_DEATH))
				return;
			ft_printf("Process %d  DIED : \
last live %d : [ A: %d / T :%d ] and [CTD = %d] => cycle : %d\n",
			cur->vm.process_nb,
			cur->vm.last_live,
			mstr->active_processes,
			mstr->total_processes,
			mstr->foamy_bat_cycle,
			mstr->cur_cycle);
}

int			process_killing(t_master *mstr, t_process **process)
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
		if (cur->vm.last_live >= mstr->foamy_bat_cycle)
		{
			verbose_life_check(mstr, cur);
			ft_bzero(cur, sizeof(t_process));
			if (!prev)
				*process = next;
			else
				prev->next = next;
			ft_memdel((void **)&cur);
		}
		prev = cur ? cur : prev;
		cur = next;
		next = cur ? cur->next : next;
	}
	update_life_check(mstr);
	return (mstr->foamy_bat_cycle);
}
