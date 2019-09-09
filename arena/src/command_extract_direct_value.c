/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_extract_direct_value.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:52:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/09 15:38:22 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

t_dir_cast		command_extract_direct_value(char *arena, int dec, int pos)
{
	int				i;
	t_dir_cast		value;

	i = -1;
	value.nb = 0;
	while (++i <= DIR_SIZE)
		value.casted[DIR_SIZE - 1 - i] =
			(t_uchar)arena_val(arena, pos + dec + i);
	return (value);
}
