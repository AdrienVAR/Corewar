/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:23:25 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/24 14:51:46 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "visu_arena.h"
#include "utils.h"

# include <stdio.h>

int		key_loop(int key, t_visu *visu)
{
	visu->update = key == SPACE ? U_ONE_TURN : visu->update;
	visu->update = key == TOUCH_M ? U_MULTI_TURN : visu->update;
	visu->multi = key == TOUCH_UP ?
		multi_turn_selector(visu->multi, 1) : visu->multi;
	visu->multi = key == TOUCH_DOWN ?
		multi_turn_selector(visu->multi, 0) : visu->multi;
	if (key == TOUCH_UP || key == TOUCH_DOWN)
		visu->update = visu->update == U_IDLE ? U_REFRESH : visu->update;
	//printf("touch pressee %d et update %d\n", key, visu->update);
	return (key);
}
