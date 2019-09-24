/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:43:45 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/24 10:51:42 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_arena.h"

void			draw_pixel(t_visu *visu, int x, int y, int color)
{
	char	*img_cont;

	img_cont = (visu->mem_ptr)[I_ADR];
	if (x < XRES && y < YRES && x >= 0 && y >= 0)
	{
		img_cont[4 * (x + y * XRES) + 2] = color % 256;
		img_cont[4 * (x + y * XRES) + 1] = (color / 256) % 256;
		img_cont[4 * (x + y * XRES) + 0] = color / (256 * 256);
	}
}
