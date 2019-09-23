/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_one_turn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:18:28 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 19:04:34 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "visu_arena.h"
#include "libft/ft_printf.h"
#include <mlx.h>

void	visu_one_turn(t_master *mstr, t_visu *visu)
{
	char *turn;

	printf("What\n");
	visu->update = visu->update == U_ONE_TURN ? U_IDLE : visu->update;
	if (!mstr->process)
		return ;
	if (mstr->cur_cycle >= mstr->options.dump
		&& mstr->options.end_dump == N_DUMP)
		return ;
	++mstr->cur_cycle;
	if (mstr->options.verbose & VERBOSE_CYCL)
		ft_printf("Current Cycle %d \n", mstr->cur_cycle);
	mstr->ctd--;
	run_cycle(mstr);
	if (mstr->ctd <= 0)
		mstr->ctd = process_killing(mstr, &mstr->process);
	reset_screen(visu->mem_ptr);
	asprintf(&turn, "Turn : %d", mstr->cur_cycle);
	mlx_string_put(visu->mem_ptr[MLX_PTR],
				visu->mem_ptr[WIN_PTR],
				1750,
				60,
				255,
				turn);
	printf("hello : %s\n", turn);
	ft_memdel((void **)&turn);
	refresh_arena(mstr, mstr->visu);
}
