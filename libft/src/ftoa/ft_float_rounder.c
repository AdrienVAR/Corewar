/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_rounder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:43:22 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:19:59 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

void		ft_float_rounder(char *str, int precision)
{
	int coma_pos;
	int i;

	coma_pos = ft_strchr(str, '.') - str;
	if ((coma_pos + precision + 1) >= MAX_STR_SZ)
		return ;
	if (str[coma_pos + precision + 1] > '4')
	{
		i = coma_pos + precision + 1;
		while (--i >= 0)
		{
			if ((str[i] < '9' && str[i] >= '0' && (str[i] = str[i] + 1)))
				break ;
			str[i] = str[i] == '9' ? '0' : str[i];
		}
		ft_float_str_addstart(str, i == -1, '1');
	}
	i = coma_pos + precision;
	while (++i < MAX_STR_SZ && str[i])
		str[i] = 0;
}
