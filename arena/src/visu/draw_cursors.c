/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cursors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:54:33 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/24 17:09:12 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "visu_arena.h"


static void	draw_square(t_visu *visu, int pos[2], int dim[2], int color)
{
	int i;
	int j;

	i = -1;
	while ( ++i < dim[0])
	{
		j = -1;
		while (++j < dim[1])
			draw_pixel(visu, pos[0] + i, pos[1] + j, color);
	}
}

static void	reset_cursor_arena(t_master *mstr)
{
	int			i;

	i = -1;
	while (++i < MEM_SIZE)
		mstr->arena[i].cursor = NO_CURSOR;
}

static void	activate_cursor(t_master *mstr)
{
	t_process	*process;
	int			pc;

	process = mstr->process;
	while (process)
	{
		pc = process->pc % MEM_SIZE;
		pc += process->pc < 0 ? MEM_SIZE : 0;
		if (process->vm.wait == 1)
			mstr->arena[pc].cursor = CURSOR_ACTIVE;
		else if (mstr->arena[pc].cursor != CURSOR_ACTIVE)
			mstr->arena[pc].cursor = CURSOR_PRESENT;
		process = process->next;
	}
}

void		draw_cursors(t_master *mstr, t_visu *visu)
{
	int pos[2];
	int dim[2];
	int i;

	reset_cursor_arena(mstr);
	activate_cursor(mstr);
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (mstr->arena[i].cursor == NO_CURSOR)
			continue;
		pos[0] = LEFT_X + i % 64 * BYTE_X;
		pos[1] = TOP_Y + i / 64 * BYTE_Y  + (BYTE_Y - 1)/ 2;
		dim[0] = BYTE_X;
		dim[1] = ((BYTE_Y - 1) / 2) * 2;
		draw_square(visu, pos, dim, mstr->arena[i].cursor == CURSOR_ACTIVE ?
		COLOR_CURSOR_ACT : COLOR_CURSOR);
	}
}
