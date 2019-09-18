/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_bin_ldbl_extract.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:56:27 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:19:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

void		ft_float_bin_ldbl_extract(t_flt_mstr *mflt)
{
	int			i;
	int			*tab;
	uintmax_t	mask;
	uintmax_t	mntsa;

	tab = mflt->cast;
	mntsa = (mflt->u_ldbl).parts.mantissa;
	tab[0] = (mflt->u_ldbl).parts.sign;
	tab[1] = (mflt->u_ldbl).parts.exp;
	mflt->sign = tab[0];
	mflt->exp = tab[1];
	if (mflt->exp - ZERO_EXP_LDBL >= 0)
		mflt->coma_pos = MAX_NB_SZ - (REDUCE_PREC);
	else
		mflt->coma_pos = 1;
	i = 1;
	mask = 0x8000000000000000;
	while (++i < 66)
	{
		tab[i] = mntsa & mask ? 1 : 0;
		mask = mask >> 1;
	}
}
