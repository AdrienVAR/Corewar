/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_give_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:21:52 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 13:38:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "utils.h"

/*
**		****************************************************
** **	Gives life to the player assigning a process to them ** **
**		****************************************************
*/

static void		born_verbose(t_process *new, t_master *mstr)
{
	ft_printf("P - %5d is BORN at PC : %5d [ A: %d / T :%d ]\n",
		new->vm.process_nb,
		new->pc,
		mstr->active_processes,
		mstr->total_processes);
}

static void		info_game_start(t_player *player)
{
	ft_printf("%*.0~Player %d%~ (%#x) of size %d Bytes : %3.0~%s%~ [%s]\n",
	player->nb + 1, player->nb, -player->nb, player->code_size,
	player->name, player->comment);
}

void			player_give_process(t_master *mstr)
{
	t_process	*process;
	t_player	*player;
	t_dir_cast	player_num;
	int			i;

	i = -1;
	ft_printf("Starting a game with %3.0~%d%~ players\n\n", mstr->nb_of_players);
	while (++i < mstr->nb_of_players)
	{
		player = mstr->players[i];
		mstr->sorted_player[i] = player;
		if (!(process = (t_process *)ft_memalloc(sizeof(t_process))))
			exit_program(mstr);
		player_num.nb = -player->nb;
		info_game_start(player);
		memrevcpy(process->registry[0], player_num.casted, DIR_SIZE);
		process->next = mstr->process;
		process->pc = player->cursor_initial_pos;
		process->vm.process_nb = ++mstr->total_processes;
		process->vm.player = player->nb;
		++mstr->active_processes;
		if (mstr->options.verbose & VERBOSE_BORN)
			born_verbose(process, mstr);
		mstr->process = process;
		mstr->last_player_live = i + 1;
	}
	ft_printf("\n");
}
