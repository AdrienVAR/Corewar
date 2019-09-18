/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_str_remove_leading_zero.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:43:42 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:21:13 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

void		ft_float_str_remove_leading_zero(char *str, int act, int e_exp)
{
	int i;

	if (!act || !str)
		return ;
	i = -1;
	while (++i < ft_abs(e_exp))
	{
		if (str[i] == '0' || str[i] == '.')
			continue ;
		else
			break ;
	}
	ft_memmove(str, str + i, MAX_STR_SZ - i);
}
