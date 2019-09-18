/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_g_rounder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:38:40 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:20:06 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

void		ft_float_g_rounder(t_flt_mstr *mflt, char *str, int precision)
{
	int i;
	int dec;

	dec = -ft_min(mflt->e_exp, 0);
	if ((dec + precision + 1) >= MAX_STR_SZ)
		return ;
	if (str[dec + precision] > '4')
	{
		i = dec + precision;
		while (--i >= 0)
		{
			if ((str[i] < '9' && str[i] >= '0' && (str[i] = str[i] + 1)))
				break ;
			str[i] = str[i] == '9' ? '0' : str[i];
			ft_float_str_addstart(str, !i, '1');
		}
		dec -= i == -1 || (str[i] == '1' && i == -(mflt->e_exp) - 1) ? 1 : 0;
		mflt->e_exp +=
			i == -1 || (str[i] == '1' && i == -(mflt->e_exp) - 1) ? 1 : 0;
	}
	i = ft_max(precision + ft_max(dec, 0), 1);
	while (i < MAX_STR_SZ && str[i])
		str[i++] = 0;
}
