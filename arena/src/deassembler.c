/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deassembler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:02:21 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/02 10:28:07 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"


static void		ft_deassembler_name(t_master *mstr, t_player *player)
{
	mstr = 0;
	player = 0;
}

void			deassembler(t_master *mstr)
{
	int i;
	t_player *player;

	i = -1;
	while (++i < mstr->nb_of_players)
	{
		player = mstr->players[i];
		player->magic = binary_read_integer(player->fd, mstr);
		ft_deassembler_name(mstr, mstr->players[i]);
	}
}
