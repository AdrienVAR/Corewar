/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_str_remove_trailing_zero.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:48:56 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 14:49:11 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"

void		ft_float_str_remove_trailing_zero(char *str, int act)
{
	int i;

	if (!act || !str)
		return ;
	i = MAX_STR_SZ;
	while (--i >= 0)
	{
		if (str[i] == '0' || !(str[i]))
			str[i] = 0;
		else if (str[i] == '.' && !(str[i] = 0))
			break ;
		else
			break ;
	}
}
