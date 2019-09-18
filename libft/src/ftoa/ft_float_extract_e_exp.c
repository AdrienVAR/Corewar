/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_extract_e_exp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:08:03 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 14:35:59 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"

void		ft_float_extract_e_exp(t_flt_mstr *mflt, char *str)
{
	int e_exp;

	if (!(mflt->u_dbl.f) && !(mflt->u_ldbl.f))
		mflt->e_exp = 0;
	else if (str[0] == '0')
	{
		e_exp = 1;
		while (str[e_exp + 1] == '0')
			e_exp++;
		mflt->e_exp = -e_exp;
	}
	else
	{
		e_exp = 0;
		while (str[e_exp + 1] && str[e_exp + 1] != '.')
			e_exp++;
		mflt->e_exp = e_exp;
	}
}
