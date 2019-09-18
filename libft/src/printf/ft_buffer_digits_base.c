/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_digits_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:34:24 by cgiron            #+#    #+#             */
/*   Updated: 2018/12/17 09:49:11 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffer_digits_base(t_master *mstr, uintmax_t nb, char *base)
{
	uintmax_t		n;
	int				i;
	int				precision;
	uintmax_t		base_sz;

	base_sz = ft_strlen(base);
	precision = mstr->options[5] - mstr->size;
	if (mstr->options[2] && ft_prec_zero_pref(mstr->options[8]))
		precision--;
	while (precision-- > 0)
		ft_update_buffer(mstr, '0');
	i = 0;
	n = 1;
	while (++i < mstr->size)
		n *= base_sz;
	while (n)
	{
		ft_update_buffer(mstr, base[nb / n]);
		nb = nb % n;
		n /= base_sz;
	}
}
