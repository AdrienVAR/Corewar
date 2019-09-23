/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_populate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:28:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 17:23:48 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"

/*
**		****************************************************
** **	Load players into the arena, therefore populating it ** **
**		****************************************************
*/

void		arena_populate(t_master *mstr)
{
	char			*arena;
	t_player		*player;
	int				step;
	int				i;
	int				j;

	i = -1;
	arena = &(mstr->arena[0]);
	step = MEM_SIZE / mstr->nb_of_players;
	ft_memset(mstr->col_arena, MAX_PLAYERS + 1, MEM_SIZE);
	while (++i < mstr->nb_of_players)
	{
		player = mstr->players[i];
		j = -1;
		while (++j < player->code_size)
		{
			arena[(i * step + j) % MEM_SIZE] = player->exec[j];
			mstr->col_arena[(i * step + j) % MEM_SIZE] = player->nb;
		}
		player->cursor_initial_pos = (i) * step;
	}
}
