/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_ldbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:24:13 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:21:38 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

void			ft_ftoa_ldbl(char *str_out, long double flt, int precision,
		int science)
{
	t_flt_mstr		mflt_val;
	t_flt_mstr		*mflt;
	t_lli			base;

	base = ft_power(10, REDUCE_WRK_BASE);
	mflt = &mflt_val;
	ft_float_mflt_init(mflt);
	ft_bzero(str_out, MAX_STR_SZ);
	(mflt->u_ldbl).f = flt;
	(mflt->u_dbl).f = 0;
	mflt->z_exp = ZERO_EXP_LDBL;
	mflt->precision = ft_max(precision, science == 2 ? 1 : 0);
	mflt->science = science;
	mflt->str_out = str_out;
	if (flt)
	{
		ft_float_bin_ldbl_extract(mflt);
		if (ft_float_ldbl_special(mflt, str_out))
			return ;
		ft_float_get_mantissa(mflt, base);
		ft_float_apply_exp(mflt, base);
	}
	ft_float_output_str(mflt);
}
