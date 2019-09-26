/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:38:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/26 21:26:22 by cizeur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include <string.h>
#include <fcntl.h>
#include <errno.h>

static void	ft_error_on_opening(char *filename, t_master *mstr)
{
	ft_putstr("Failed to open the file \"");
	ft_putstr(filename);
	ft_putstr("\" : ");
	ft_putstr(strerror(errno));
	ft_putchar('\n');
	exit_program(mstr);
}

void		file_loading(t_master *mstr, t_player *player, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_on_opening(filename, mstr);
	player->fd = fd;
	player->binary_name = filename;
}
