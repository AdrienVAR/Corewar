/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:53:50 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 18:28:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "visu_arena.h"
#include "mlx/mlx.h"
#include "utils.h"

void		winner_background(t_master *mstr, t_visu *visu)
{
	int pos[2];
	int dim[2];
	int color;

	pos[0] = RIGHT_BAR_X + STD_BUF;
	pos[1] = YRES - BOTTOM_Y - WINNER_Y;
	dim[0] = RIGHT_BAR_SIZE - STD_BUF;
	dim[1] = WINNER_Y;
	if (mstr->someone_lived)
	{
		color = player_color(mstr->last_player_live);
		draw_square_image(visu, pos, dim, color);
	}
	else
		draw_square_image(visu, pos, dim, color_dimmer(COLOR_BASIC, 50));
}

void		refresh(t_master *mstr, t_visu *visu)

{
	clean_image_background(visu);
	draw_cursors_image(mstr, visu);
	if (visu->update == U_END)
		winner_background(mstr, visu);
	flush_image(visu);
	refresh_sidebar(mstr, visu);
	refresh_arena(mstr, mstr->visu);
	visu->update = visu->update == U_REFRESH ? U_IDLE : visu->update;
	visu->ended = visu->update == U_END ? 1 : visu->ended;
}
