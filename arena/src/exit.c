/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:14:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/11 18:45:13 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include <stdlib.h>

/*
**		***************************
** **	Provide clean exit on ERROR ** **
**		***************************
*/

void		free_player(t_player **player)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		ft_bzero(player[i], sizeof(t_player));
		ft_memdel((void **)&player[i]);
	}
}

void		free_process(t_process *process)
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

void		free_everything(t_master *mstr)
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

void		exit_program(t_master *mstr)
{

	ft_putstr("ERROR\n");
	free_everything(mstr);
	exit(1);
}
