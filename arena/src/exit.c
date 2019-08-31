/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:14:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/31 15:01:40 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include <stdlib.h>

void		free_everything(t_master *mstr)
{
	if (mstr)
	{
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
