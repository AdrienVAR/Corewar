/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:40:36 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 17:24:17 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include "visu_arena.h"
#include "arena.h"
#include <mlx.h>

int				color_dimmer(int color, int dim)
{
	int dimmed;

	dimmed = (color & 0xff) * dim / 100;
	dimmed *= 256;
	dimmed += ((color >> 8) & 0xff) * dim / 100;
	dimmed *= 256;
	dimmed += (color & 0xff) * dim / 100;
	return (dimmed);
}

int				color_player(int player)
{
	if (player == MAX_PLAYERS + 1)
		return (color_dimmer(COLOR_BASIC, 50));
	else if (player == 1)
		return (P1_COL);
	else if (player == 2)
		return (P2_COL);
	else if (player == 3)
		return (P3_COL);
	else if (player == 4)
		return (P4_COL);
	else
		return (COLOR_BASIC);
}

void			refresh_arena(t_master *mstr, t_visu *visu)
{
	char		byte[3];
	static char hexa[17] = "0123456789abcdef";
	int			i;
	int			color;

	i = -1;
	while (++i < MEM_SIZE)
	{
		byte[2] = mstr->arena[i];
		byte[0] = (hexa[(t_uchar)byte[2] / 16]);
		byte[1] = (hexa[(t_uchar)byte[2] % 16]);
		byte[2] = 0;
		color = color_player(mstr->col_arena[i]);
		mlx_string_put(visu->mem_ptr[MLX_PTR],
						visu->mem_ptr[WIN_PTR],
						LEFT_X + i % 64 * 22,
						TOP_Y + i / 64 * (YRES - (TOP_Y + BOTTOM_Y)) / (MEM_SIZE / 64),
						color,
						byte);
	}
}
