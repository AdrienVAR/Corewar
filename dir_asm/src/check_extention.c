/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:25:25 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/02 11:16:43 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check if file is a .s
*/

int		check_extention(char *file)
{
	int i;

	i = ft_strlen(file) - 2;
	if (i <= 0 || ft_strcmp(file + i, ".s"))
		return (0);
	else
		return (1);
}
