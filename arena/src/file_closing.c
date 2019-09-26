/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_closing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:08:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/26 21:26:59 by cizeur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include <unistd.h>

void		file_closing(t_player *player)
{
	if (player->fd)
		close(player->fd);
	player->fd = 0;
}
