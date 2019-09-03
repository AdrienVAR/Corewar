/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_populate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:28:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/03 16:06:10 by cgiron           ###   ########.fr       */
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

	i = -1;
	arena = &(mstr->arena[0]);
	step = MEM_SIZE / mstr->nb_of_players;
	while (++i < mstr->nb_of_players)
	{
		player = mstr->players[i];
		ft_memcpy(arena + i * step, player->exec, player->code_size);
		player->cursor_initial_pos = i * step;
	}
}
