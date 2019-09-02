/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_closing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:08:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/02 16:21:24 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <unistd.h>

void		file_closing(t_master *mstr)
{
	t_player	*player;
	int			i;

	i = -1;
	while (++i < mstr->nb_of_players)
	{
		player = mstr->players[i];
		if (player->fd)
			close(player->fd);
		player->fd = 0;
	}
}
