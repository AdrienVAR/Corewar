/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:01:10 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 14:12:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include <stdlib.h>

/*
**		***************************
** **	Provide clean exit on ERROR ** **
**		***************************
*/

void			exit_visu(t_master *mstr)
{
	if (mstr)
		clear_window(mstr->visu);
	free_everything(mstr);
	exit(0);
}
