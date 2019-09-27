/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:38:03 by cizeur            #+#    #+#             */
/*   Updated: 2019/09/27 10:13:17 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include <stdlib.h>

/*
**		****************
** **	Free all mallocs ** **
**		****************
*/

static void		free_player(t_player **player)
{
	int i;

	i = -1;

	while (++i < MAX_PLAYERS)
	{
		file_closing(player[i]);
		ft_bzero(player[i], sizeof(t_player));
		ft_memdel((void **)&player[i]);
	}
}

static void		free_process(t_process *process)
{
	t_process *stock;

	while (process)
	{
		stock = process->next;
		ft_bzero(process, sizeof(process));
		ft_memdel((void **)&process);
		process = stock;
	}
}

void			free_everything(t_master *mstr)
{
	if (mstr)
	{
		free_player(&(mstr->players[0]));
		free_process(mstr->process);
		ft_bzero(mstr, sizeof(t_master));
		free(mstr);
	}
	mstr = 0;
}
