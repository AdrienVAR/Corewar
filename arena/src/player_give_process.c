/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_give_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:21:52 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/09 17:27:45 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"

/*
**		****************************************************
** **	Gives life to the player assigning a process to them ** **
**		****************************************************
*/

void		player_give_process(t_master *mstr)
{
	t_process	*process;
	t_player	*player;
	t_dir_cast	player_num;
	int			i;

	i = -1;
	while (++i < mstr->nb_of_players)
	{
		player = mstr->players[i];
		if (!(process = (t_process *)ft_memalloc(sizeof(t_process))))
			exit_program(mstr);
		player_num.nb = player->nb;
		memrevcpy(process->registry[0], player_num.casted, DIR_SIZE);
		process->next = mstr->process;
		process->pc = player->cursor_initial_pos;
		mstr->process = process;
	}
}
