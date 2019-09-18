/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_u_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:25:50 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:28:40 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_fetch_u_int(t_printf *mstr)
{
	int			size;
	uintmax_t	nb;

	size = mstr->options[7];
	nb = (uintmax_t)va_arg(mstr->arg, uintmax_t);
	mstr->fringe[1] = nb < 1 ? 0 : 1;
	if (mstr->options[8] == TYPE_CAP_U || mstr->options[8] == TYPE_CAP_O)
		nb = (unsigned long int)nb;
	else if (size == 2)
		nb = (unsigned long int)nb;
	else if (size == 5)
		nb = (unsigned long long int)nb;
	else if (size == 6)
		nb = (uintmax_t)nb;
	else if (size == 1)
		nb = (unsigned short)nb;
	else if (size == 4)
		nb = (unsigned char)nb;
	else if (size == 7)
		nb = (size_t)nb;
	else
		nb = (unsigned int)nb;
	return ((uintmax_t)nb);
}
