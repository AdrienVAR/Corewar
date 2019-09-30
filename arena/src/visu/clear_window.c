/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:32:07 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 17:20:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include "mlx/mlx.h"

void			clear_window(t_visu *visu)
{
	if (visu)
	{
		if ((visu->mem_ptr)[MLX_PTR] && (visu->mem_ptr)[I_PTR])
			mlx_destroy_image(visu->mem_ptr[MLX_PTR],
				visu->mem_ptr[I_PTR]);
		if ((visu->mem_ptr)[MLX_PTR] && visu->header)
			mlx_destroy_image(visu->mem_ptr[MLX_PTR],
				visu->header);
		if ((visu->mem_ptr)[WIN_PTR] && (visu->mem_ptr)[MLX_PTR])
			mlx_destroy_window((visu->mem_ptr)[MLX_PTR],
				(visu->mem_ptr)[WIN_PTR]);
		ft_bzero(visu->mem_ptr, sizeof(void *) * 4);
		visu->header = 0;
	}
	ft_memdel((void **)&visu);
}
