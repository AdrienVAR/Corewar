/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_write_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:49:40 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/23 12:13:48 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"

void		ft_float_write_str(char *str_out, t_flt_mstr *mflt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < mflt->coma_pos - 1 && !(mflt->nb)[i])
		i++;
	j += ft_putnbr_str(str_out + j, (mflt->nb)[i++], -1);
	while (i < MAX_NB_SZ)
	{
		if (i == mflt->coma_pos)
			str_out[j++] = '.';
		j += ft_putnbr_str(str_out + j, (mflt->nb)[i++],
					REDUCE_WRK_BASE);
	}
}
