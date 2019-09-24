/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:53:50 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/24 16:08:47 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"
#include "utils.h"
#include <mlx.h>

void		refresh(t_master *mstr, t_visu *visu)
{
	char *string;

	clean_image_background(visu);
	draw_cursors(mstr, visu);
	reset_screen(visu);
	ft_asprintf(&string, "Cycle : %d", mstr->cur_cycle);
	mlx_string_put(visu->mem_ptr[MLX_PTR], visu->mem_ptr[WIN_PTR],
				RIGHT_BAR_X + STD_BUF, TOP_Y, COLOR_BASIC, string);
	ft_memdel((void **)&string);
	ft_asprintf(&string, "MULTI : %d", visu->multi);
	mlx_string_put(visu->mem_ptr[MLX_PTR], visu->mem_ptr[WIN_PTR],
				RIGHT_BAR_X + STD_BUF, TOP_Y + 1 * STD_NEW_LINE, COLOR_BASIC, string);
	ft_memdel((void **)&string);
	refresh_arena(mstr, mstr->visu);
	visu->update = visu->update == U_REFRESH ? U_IDLE : visu->update;
}
