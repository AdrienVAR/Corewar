/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_ldbl_special.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:15:42 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:20:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

int		ft_float_ldbl_special(t_flt_mstr *mflt, char *str_out)
{
	int			special;
	uintmax_t	mntsa;

	special = 0;
	mntsa = (mflt->u_ldbl).parts.mantissa;
	if (mflt->exp == 0x7FFF && (special = 1)
		&& (mntsa << 2 != 0 || mntsa >> 62 == 3))
		ft_memcpy(str_out, "nan", 4);
	else if (mflt->exp == 0x7FFF && (special = 1)
			&& mflt->sign == 0 && mntsa >> 62 != 3)
		ft_memcpy(str_out, "inf", 4);
	else if (mflt->exp == 0x7FFF && (special = 1)
			&& mflt->sign != 0 && mntsa >> 62 != 3)
		ft_memcpy(str_out, "-inf", 5);
	return (special ? 1 : 0);
}
