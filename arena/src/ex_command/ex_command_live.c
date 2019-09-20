/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_live.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/20 19:59:29 by cizeur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"

static void		live_verbose(t_process *process)
{
	ft_printf("P - %5d | op : %5s %d\n",
		process->vm.process_nb,
		process->vm.command.op.name,
		process->vm.command.param_conv[0].nb);
}

void			ex_command_live(t_master *mstr, t_process *process, char *arena)
{
	t_command	command;

	(void)arena;
	command = process->vm.command;
	process->vm.last_live = -1;
	process->vm.alive = command.param_conv[0].nb;
	if (mstr->options.verbose & VERBOSE_OPER)
		live_verbose(process);
	if (process->vm.alive >= 1
		&& process->vm.alive <= mstr->nb_of_players)
		mstr->last_player_live = process->vm.alive;
	process->vm.alive = 0;
	mstr->live_signal++;
}
