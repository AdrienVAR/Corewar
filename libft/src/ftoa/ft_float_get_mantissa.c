/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_get_mantissa.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:39:15 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/22 13:40:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"

void		ft_float_get_mantissa(t_flt_mstr *mflt, t_lli base)
{
	int		neg_pow_two[REDUCE_PREC + 1];
	int		*mantis;
	int		*ptr_neg;
	int		i;

	i = -1;
	mantis = mflt->mantisa;
	ptr_neg = neg_pow_two;
	while (++i < REDUCE_PREC + 1)
	{
		mantis[i] = 0;
		neg_pow_two[i] = 0;
	}
	neg_pow_two[0] = 1;
	i = 1;
	while (++i < CAST_SZ)
	{
		if ((mflt->cast)[i] == 1)
			ft_add_tab(&mantis, ptr_neg, REDUCE_PREC + 1, base);
		ft_div_tab(&ptr_neg, 2, REDUCE_PREC + 1, base);
	}
}
