/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:23:56 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:21:03 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_fetch_int(t_master *mstr)
{
	int			size;
	intmax_t	nb;

	size = mstr->options[7];
	nb = (intmax_t)va_arg(mstr->arg, intmax_t);
	mstr->fringe[0] = nb ? 1 : 0;
	if (size == 2 || mstr->options[8] == TYPE_CAP_D)
		nb = (long int)nb;
	else if (size == 1)
		nb = (short int)nb;
	else if (size == 4)
		nb = (char)nb;
	else if (size == 5)
		nb = (long long int)nb;
	else if (size == 6)
		nb = (intmax_t)nb;
	else if (size == 7)
		nb = (size_t)nb;
	else
		nb = (int)nb;
	return ((intmax_t)nb);
}
