/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_flt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:21:35 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:22:55 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fetch_flt(t_printf *mstr, double *dbl, long double *ldbl)
{
	int size;

	mstr->options[5] = mstr->options[5] >= 0 ? mstr->options[5] : DEFAULT_PREC;
	size = mstr->options[7];
	*dbl = 0.;
	*ldbl = (long double)0.;
	if (size == 3)
		*ldbl = (long double)va_arg(mstr->arg, long double);
	else
		*dbl = (double)va_arg(mstr->arg, double);
}
