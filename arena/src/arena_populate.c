/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_populate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:28:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/24 09:23:10 by cgiron           ###   ########.fr       */
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
	t_arena			*arena;
	t_player		*player;
	int				step;
	int				i;
	int				j;

	i = -1;
	arena = &(mstr->arena[0]);
	step = MEM_SIZE / mstr->nb_of_players;
	while (++i < mstr->nb_of_players)
	{
		player = mstr->players[i];
		j = -1;
		while (++j < player->code_size)
			arena_val_set(arena, player->exec[j], i * step + j, player->nb);
		player->cursor_initial_pos = (i) * step;
	}
}
