/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:05:07 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 12:06:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_arena.h"
#include "utils.h"

int				player_color(int player)
{
	if (player == 1)
		return (P1_COL);
	else if (player == 2)
		return (P2_COL);
	else if (player == 3)
		return (P3_COL);
	else if (player == 4)
		return (P4_COL);
	else
		return (color_dimmer(COLOR_BASIC, 50));
}
