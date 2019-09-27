/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_live.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 13:46:41 by cgiron           ###   ########.fr       */
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

static void	player_sort_living(t_master *mstr, t_process *process)
{
	int			i;
	t_player	*player;
	int			live;
	t_player	*stock[2];

	live = process->vm.alive - 1;
	player = mstr->players[live];
	i = 0;
	stock[1] = mstr->sorted_player[0];
	while (i < mstr->nb_of_players - 1)
	{
		stock[0] = mstr->sorted_player[i + 1];
		if (stock[1]->nb == live + 1)
			break ;
		mstr->sorted_player[i + 1] = stock[1];
		stock[1] = stock[0];
		i++;
	}
	mstr->sorted_player[0] = player;
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
		player_sort_living(mstr, process);
		player_live_verbose(mstr);
	}
	process->vm.alive = 0;
	mstr->live_signal++;
}
