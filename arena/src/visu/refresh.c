/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:53:50 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 10:32:10 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void		refresh(t_master *mstr, t_visu *visu)

{
	clean_image_background(visu);
	draw_cursors(mstr, visu);
	flush_image(visu);
	refresh_sidebar(mstr, visu);
	refresh_arena(mstr, mstr->visu);
	visu->update = visu->update == U_REFRESH ? U_IDLE : visu->update;
}
