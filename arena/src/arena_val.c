/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:23:16 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/24 09:18:58 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

t_uchar	arena_val_get(t_arena *arena, int ind)
{
	ind = ind % MEM_SIZE;
	ind = ind < 0 ? ind + MEM_SIZE : ind;
	return ((t_uchar)arena[ind].value);
}

void	arena_val_set(t_arena *arena, char c, int ind, int player)
{
	ind = ind % MEM_SIZE;
	ind = ind < 0 ? ind + MEM_SIZE : ind;
	arena[ind].value = (t_uchar)c;
	arena[ind].player = player;
}
