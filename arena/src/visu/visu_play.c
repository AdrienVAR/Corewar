/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:18:28 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 10:22:26 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "visu_arena.h"
#include "libft/ft_printf.h"

void	visu_play_one_turn(t_master *mstr, t_visu *visu)
{
	visu->update = visu->update == U_ONE_TURN ? U_REFRESH : visu->update;
	if ((!mstr->process || (mstr->cur_cycle >= mstr->options.dump
		&& mstr->options.end_dump == N_DUMP))
		&& (visu->update = U_REFRESH))
		return ;
	++mstr->cur_cycle;
	if (mstr->options.verbose & VERBOSE_CYCL)
		ft_printf("Current Cycle %d \n", mstr->cur_cycle);
	mstr->ctd--;
	run_cycle(mstr);
	if (mstr->ctd <= 0)
		mstr->ctd = process_killing(mstr, &mstr->process);
}

void	visu_play_multi_turn(t_master *mstr, t_visu *visu)
{
	int i;

	visu->update = visu->update == U_MULTI_TURN ? U_REFRESH : visu->update;
	i = -1;
	while (++i < visu->multi)
		visu_play_one_turn(mstr, visu);
}

void	visu_play_till_action(t_master *mstr, t_visu *visu)
{
	while (visu->update != U_REFRESH && !mstr->something_happened)
		visu_play_one_turn(mstr, visu);
	mstr->something_happened = 0;
	visu->update = U_REFRESH;
}
