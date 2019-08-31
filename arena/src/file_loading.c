/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:38:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/31 16:38:42 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include <string.h>
#include <fcntl.h>
#include <errno.h>

static void	ft_init_player(t_master *mstr, char *binary, int fd, int player_n)
{
	t_player *player;

	player = mstr->players[player_n];
	player->fd = fd;
	player->binary = binary;
}

static int	ft_is_option(char ***argv, int *argc)
{
	if (!ft_strcmp(**argv, OPT_N))
	{
		(*argv)++;
		(*argc)--;
		return (1);
	}
	else if (!ft_strcmp(**argv, OPT_DUMP))
		return (1);
	return (0);
}

static void	ft_error_on_opening(char **argv, t_master *mstr)
{
	ft_putstr("Failed to open the file \"");
	ft_putstr(*argv);
	ft_putstr("\" : ");
	ft_putstr(strerror(errno));
	ft_putchar('\n');
	exit_program(mstr);
}

void		file_loading(t_master *mstr, int argc, char **argv)
{
	int i;
	int fd;

	i = 0;
	while (argc-- && *(argv++) && i < MAX_PLAYERS)
	{
		if (ft_is_option(&argv, &argc))
			continue;
		fd = open(*argv, O_RDONLY);
		if (fd == -1)
			ft_error_on_opening(argv, mstr);
		ft_init_player(mstr, *argv, fd, i);
		i++;
	}
}
