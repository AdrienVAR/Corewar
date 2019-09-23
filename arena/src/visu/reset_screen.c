/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:42:42 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 18:45:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "visu_arena.h"

void	reset_screen(void **mem_ptr)
{
	mlx_put_image_to_window(mem_ptr[MLX_PTR], mem_ptr[WIN_PTR],
		mem_ptr[I_PTR], 0, 0);
}
