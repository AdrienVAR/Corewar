/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_dbl_special.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:15:27 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:19:33 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

int					ft_float_dbl_special(t_flt_mstr *mflt, char *str_out)
{
	int			special;
	uintmax_t	mntsa;

	special = 0;
	mntsa = (mflt->u_dbl).parts.mantissa;
	if (mflt->exp == 0x7FF && (special = 1) && mntsa != 0)
		ft_memcpy(str_out, "nan", 4);
	else if (mflt->exp == 0x7FF && (special = 1) && mflt->sign == 0)
		ft_memcpy(str_out, "inf", 4);
	else if (mflt->exp == 0x7FF && (special = 1) && mflt->sign != 0)
		ft_memcpy(str_out, "-inf", 5);
	return (special ? 1 : 0);
}
