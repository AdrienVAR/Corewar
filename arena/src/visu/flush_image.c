/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   reset_screen.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cgiron <cgiron@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/23 18:42:42 by cgiron			#+#	#+#			 */
/*   Updated: 2019/09/24 10:43:56 by cgiron		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "visu_arena.h"
#include "libft/libft.h"

void	clean_image_background(t_visu *visu)
{
	int i;
	int j;

	i = -1;
	while (++i < XRES)
	{
		j = -1;
		while (++j < YRES)
			draw_pixel(visu, i, j, COLOR_BACKGROUND);
	}
}

void	flush_image(t_visu *visu)
{
	mlx_put_image_to_window(visu->mem_ptr[MLX_PTR],
		visu->mem_ptr[WIN_PTR], visu->mem_ptr[I_PTR], 0, 0);
	mlx_put_image_to_window(visu->mem_ptr[MLX_PTR],
		visu->mem_ptr[WIN_PTR], visu->header,
			(XRES - visu->header_size[0]) / 2, 15);
}
