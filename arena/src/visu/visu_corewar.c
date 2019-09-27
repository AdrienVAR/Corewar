/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:35:46 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 17:30:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "arena.h"
#include "visu_arena.h"
#include "libft/libft.h"

static int		close_click(t_master *mstr)
{
	mstr->no_error = 1;
	exit_visu(mstr);
	return (1);
}

static int		loop_hook(t_master *mstr)
{
	if (mstr->visu->update == U_STOP)
		close_click(mstr);
	if (mstr->visu->ended)
		return (1);
	if (mstr->visu->update == U_ONE_TURN)
		visu_play_one_turn(mstr, mstr->visu);
	if (mstr->visu->update == U_TILL_THE_END
	|| mstr->visu->update == U_MULTI_TURN)
		visu_play_multi_turn(mstr, mstr->visu);
	if (mstr->visu->update == U_TILL_SOMETHING_HAPPEN)
		visu_play_till_action(mstr, mstr->visu);
	if (mstr->visu->update != U_IDLE)
		refresh(mstr, mstr->visu);
	return (1);
}

static void		init_window(t_master *mstr, t_visu *visu)
{
	int data_prm[3];

	visu->mem_ptr[MLX_PTR] = mlx_init();
	if (!(visu->mem_ptr[WIN_PTR] =
		mlx_new_window(visu->mem_ptr[MLX_PTR],
	XRES, YRES, "Corewar Arena")))
		exit_visu(mstr);
	visu->mem_ptr[I_PTR] = mlx_new_image(visu->mem_ptr[MLX_PTR], XRES, YRES);
	if (!visu->mem_ptr[I_PTR])
		exit_visu(mstr);
	visu->mem_ptr[I_ADR] = mlx_get_data_addr(visu->mem_ptr[I_PTR],
		&(data_prm[0]), &(data_prm[1]), &(data_prm[2]));
	visu->header = mlx_xpm_file_to_image(visu->mem_ptr[MLX_PTR],
		"./header.xpm", &(visu->header_size[0]), &(visu->header_size[1]));
	if (!visu->header)
		ft_putstr("Image header not found\n");
}

static void		hook_loops(t_master *mstr, t_visu *visu)
{
	mlx_key_hook((visu->mem_ptr)[WIN_PTR], key_simple_press, visu);
	mlx_hook((visu->mem_ptr)[WIN_PTR], 2, 0, key_loop, visu);
	mlx_hook((visu->mem_ptr)[WIN_PTR], 17, 0, close_click, mstr);
	mlx_loop_hook((visu->mem_ptr)[MLX_PTR], loop_hook, mstr);
	mlx_expose_hook((visu->mem_ptr)[WIN_PTR], loop_hook, mstr);
}

void			visu_corewar(t_master *mstr)
{
	if (!(mstr->visu = (t_visu *)ft_memalloc(sizeof(t_visu))))
		exit_program(mstr);
	mstr->ctd = mstr->foamy_bat_cycle;
	init_window(mstr, mstr->visu);
	hook_loops(mstr, mstr->visu);
	mstr->visu->multi = 1;
	mstr->visu->update = U_REFRESH;
	mlx_loop((mstr->visu->mem_ptr)[MLX_PTR]);
}
