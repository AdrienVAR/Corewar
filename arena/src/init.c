/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:11:04 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/31 16:38:56 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"

void		init(t_master **mstr)
{
	t_master	*mstr_val;
	int			i;

	if (!(mstr_val = (t_master *)ft_memalloc(sizeof(t_master))))
		exit_program(mstr_val);
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (!(mstr_val->players[i] =
			(t_player *)ft_memalloc(sizeof(t_player) * MAX_PLAYERS)))
			exit_program(mstr_val);
	}
	*mstr = mstr_val;
}
