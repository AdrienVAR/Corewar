/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:58:49 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 18:05:55 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_arena.h"
#include "mlx/mlx.h"

void		draw_square_image(t_visu *visu, int pos[2], int dim[2], int color)
{
	int i;
	int j;

	i = -1;
	while (++i < dim[0])
	{
		j = -1;
		while (++j < dim[1])
			draw_pixel(visu, pos[0] + i, pos[1] + j, color);
	}
}
