/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:14:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/21 17:40:15 by cizeur           ###   ########.fr       */
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

	ft_putstr("ERROR\n");
	free_everything(mstr);
	exit(1);
}
