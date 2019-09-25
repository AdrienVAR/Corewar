/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:40:36 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 12:36:15 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "utils.h"
#include "visu_arena.h"
#include <mlx.h>

void			refresh_arena(t_master *mstr, t_visu *visu)
{
	char		byte[3];
	static char hexa[17] = "0123456789abcdef";
	int			i;
	int			color;

	i = -1;
	while (++i < MEM_SIZE)
	{
		byte[2] = mstr->arena[i].value;
		byte[0] = (hexa[(t_uchar)byte[2] / 16]);
		byte[1] = (hexa[(t_uchar)byte[2] % 16]);
		byte[2] = 0;
		color = player_color(mstr->arena[i].player);
		mlx_string_put(visu->mem_ptr[MLX_PTR],
						visu->mem_ptr[WIN_PTR],
						LEFT_X + i % 64 * BYTE_X,
						TOP_Y + i / 64 * BYTE_Y,
						color,
						byte);
	}
}
