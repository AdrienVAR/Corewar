/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:14:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 17:11:11 by cgiron           ###   ########.fr       */
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

void			exit_program(t_master *mstr)
{
	if (!mstr || !mstr->no_error)
		ft_putstr("ERROR\n");
	free_everything(mstr);
	exit(1);
}
