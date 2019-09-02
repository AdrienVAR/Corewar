/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deassembler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:02:21 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/02 14:26:26 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			deassembler(t_master *mstr)
{
	int			i;
	t_player	*player;

	i = -1;
	while (++i < mstr->nb_of_players)
	{
		player = mstr->players[i];
		player->magic = binary_read_integer(player->fd, mstr);
		binary_read_string(
			player->fd, &(player->name[0]), PROG_NAME_LENGTH, mstr);
		binary_read_null(player->fd, mstr);
		player->code_size = binary_read_integer(player->fd, mstr) - 1;
		binary_read_string(
			player->fd, &(player->comment[0]), COMMENT_LENGTH, mstr);
		binary_read_null(player->fd, mstr);
		if (player->code_size < CHAMP_MAX_SIZE && player->code_size > 0)
			binary_read_string(
			player->fd, &(player->exec[0]), player->code_size, mstr);
	}
}
