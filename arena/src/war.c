/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:07:46 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/03 16:13:48 by cgiron           ###   ########.fr       */
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
	cur_process = 0;
	arena = 0;
	ft_putstr("RUUUUUN COMMAND RUUUUUUUN !!!\n");
}

void			set_wait_time(t_process *cur_process, char pc)
{
	t_op operation;

	operation = operation_get_info(pc);
	cur_process->vm.wait = operation.duration;
}

void			run_cycle(t_master *mstr)
{
	t_process *cur_process;

	cur_process = mstr->process;
	while (cur_process)
	{
		if (cur_process->vm.wait == 1)
			run_command(cur_process, mstr->arena);
		else if (!cur_process->vm.wait)
			set_wait_time(cur_process, mstr->arena[cur_process->pc]);
		cur_process->vm.wait--;
		cur_process = cur_process->next;
	}
}

void			war(t_master *mstr)
{

	while (mstr->cur_cycle < 15)
	{
		++mstr->cur_cycle;
		run_cycle(mstr);
	}
}
