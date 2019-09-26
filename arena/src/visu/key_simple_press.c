/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_simple_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:23:25 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/26 10:55:19 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "visu_arena.h"

int		key_simple_press(int key, t_visu *visu)
{
	visu->update = key == ESCAPE ? U_STOP : visu->update;
	visu->update = key == TOUCH_P ? U_TILL_THE_END : visu->update;
	return (key);
}
