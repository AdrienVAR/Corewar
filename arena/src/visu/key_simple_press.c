/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_simple_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:23:25 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 19:02:24 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "visu_arena.h"

# include <stdio.h>

int		key_simple_press(int key, t_visu *visu)
{
	visu->update = key == ESCAPE ? U_STOP : visu->update;
	printf("touch pressee %d et update %d\n", key, visu->update);
	return (key);
}
