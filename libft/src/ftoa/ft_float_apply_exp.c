/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_apply_exp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:42:59 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:18:57 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

void		ft_float_apply_exp(t_flt_mstr *mflt, t_lli base)
{
	int *ptr;
	int sign;
	int exp;
	int i;
	int j;

	ptr = mflt->nb;
	sign = (mflt->exp - mflt->z_exp) >= 0 ? 1 : -1;
	i = 0;
	while ((j = -1) && sign == 1 && i < MAX_NB_SZ - (REDUCE_PREC + 1))
		ptr[i++] = 0;
	while (++j < (REDUCE_PREC + 1))
		ptr[i + j] = (mflt->mantisa)[j];
	i = i + j;
	while (sign == -1 && i < MAX_NB_SZ)
		ptr[i++] = 0;
	exp = ft_abs(mflt->z_exp - mflt->exp);
	while ((i = ft_power(2, STEP_EXP)) && exp > STEP_EXP)
	{
		sign == -1 ? ft_div_tab(&ptr, i, MAX_NB_SZ, base) :
			ft_mult_tab(&ptr, i, MAX_NB_SZ, base);
		exp -= STEP_EXP;
	}
	sign == -1 ? ft_div_tab(&ptr, ft_power(2, exp), MAX_NB_SZ, base) :
		ft_mult_tab(&ptr, ft_power(2, exp), MAX_NB_SZ, base);
}
