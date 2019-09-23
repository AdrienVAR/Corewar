/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:38:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 10:19:11 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include <string.h>
#include <fcntl.h>
#include <errno.h>

static void	ft_init_player(t_master *mstr, char *bin_name, int fd, int i)
{
	t_player *player;

	player = mstr->players[i];
	player->fd = fd;
	player->binary_name = bin_name;
}

static void	ft_error_on_opening(char *filename, t_master *mstr)
{
	ft_putstr("Failed to open the file \"");
	ft_putstr(filename);
	ft_putstr("\" : ");
	ft_putstr(strerror(errno));
	ft_putchar('\n');
	exit_program(mstr);
}

void		file_loading(t_master *mstr, char **argv)
{
	int		i;
	int		fd;
	char	*filename;
	int		player_nb;

	i = -1;
	while (++i < mstr->nb_of_players)
	{
		player_nb = mstr->options.player[mstr->options.player[i][0] - 1][1];
		filename = argv[player_nb];
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			ft_error_on_opening(filename, mstr);
		ft_init_player(mstr, filename, fd, i);
	}
}
