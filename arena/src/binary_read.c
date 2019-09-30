/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:17:22 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 18:34:16 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <unistd.h>
#include "utils.h"
#include <stdlib.h>

static void		message_exit(t_player *player, t_master *mstr, int r)
{
	if (r == -1)
		ft_printf("%*.0~Player %d => %s%~ Fail on read\n",
			player->nb + 1, player->nb, player->binary_name);
	else
		ft_printf("%*.0~Player %d => %s%~ too short\n",
			player->nb + 1, player->nb, player->binary_name);
	exit_program(mstr);
}

int				binary_read_integer(t_player *player, t_master *mstr)
{
	char			nb_str[4];
	int				read_ret;
	t_int_cast		caster;
	int				fd;

	fd = player->fd;
	caster.nb = 0;
	ft_bzero(nb_str, 4);
	read_ret = read(fd, &nb_str, 4);
	if (read_ret != 4)
		message_exit(player, mstr, read_ret);
	memrevcpy(caster.casted, nb_str, 4);
	return (caster.nb);
}

void			binary_read_string(t_player *player, char *str,
					int sz, t_master *mstr)
{
	int				read_ret;
	int				nb;
	int				fd;

	fd = player->fd;
	nb = 0;
	ft_bzero(str, sz + 1);
	read_ret = read(fd, str, sz);
	if (read_ret != sz)
		message_exit(player, mstr, read_ret);
}

void			binary_read_null(t_player *player, t_master *mstr)
{
	int zero;

	if (!(zero = binary_read_integer(player, mstr)))
		return ;
	ft_printf("%*.0~Player %d => %s%~ Invalid HEADER\n",
		player->nb + 1, player->nb, player->binary_name);
	exit_program(mstr);
}
