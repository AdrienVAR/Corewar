/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidebar_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 12:17:04 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 12:21:11 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "visu_arena.h"
#include "mlx/mlx.h"
#include "utils.h"

void	sidebar_text(t_visu *visu, char *line, int color, int line_nb)
{
	if (line_nb >= 0)
		mlx_string_put(visu->mem_ptr[MLX_PTR], visu->mem_ptr[WIN_PTR],
				RIGHT_BAR_X + STD_BUF, TOP_Y + line_nb * STD_NEW_LINE,
				color, line);
	else
		mlx_string_put(visu->mem_ptr[MLX_PTR], visu->mem_ptr[WIN_PTR],
				RIGHT_BAR_X + 2 * STD_BUF, TOP_Y - line_nb * STD_NEW_LINE,
				color_dimmer(color, 80), line);
	ft_memdel((void **)&line);
}
