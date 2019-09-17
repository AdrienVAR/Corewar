/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:23:16 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/17 14:37:52 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

t_uchar	arena_val_get(char *arena, int ind)
{
	ind = ind % MEM_SIZE;
	ind = ind < 0 ? ind + MEM_SIZE : ind;
	return ((t_uchar)arena[ind]);
}

void	arena_val_set(char *arena, char c, int ind)
{
	ind = ind % MEM_SIZE;
	ind = ind < 0 ? ind + MEM_SIZE : ind;
	arena[ind] = (t_uchar)c;
}
