/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_live.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 12:15:00 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"

static void	live_verbose(t_process *process)
{
	ft_printf("P - %5d | op : %5s %d\n",
		process->vm.process_nb,
		process->vm.command.op.name,
		process->vm.command.param_conv[0].nb);
}

static void	player_live_verbose(t_master *mstr)
{
	if (!(mstr->options.verbose & VERBOSE_LIFE))
		return ;
	ft_printf("Player %d : %s squeezed in a live signal\n",
		mstr->last_player_live,
		mstr->players[mstr->last_player_live - 1]->name);
}

void		ex_command_live(t_master *mstr, t_process *process, t_arena *arena)
{
	t_command	command;

	(void)arena;
	command = process->vm.command;
	process->vm.last_live = -1;
	process->vm.alive = -command.param_conv[0].nb;
	if (mstr->options.verbose & VERBOSE_OPER)
		live_verbose(process);
	if (process->vm.alive >= 1
		&& process->vm.alive <= mstr->nb_of_players)
	{
		mstr->last_player_live = process->vm.alive;
		mstr->players[process->vm.alive - 1]->life_signals++;
		mstr->someone_lived = 1;
		player_live_verbose(mstr);
	}
	process->vm.alive = 0;
	mstr->live_signal++;
}
