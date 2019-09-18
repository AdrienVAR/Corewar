/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:47:12 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:06:22 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_int_padding(t_master *mstr, int nb, char c, int act)
{
	intmax_t	n;
	int			padding;
	int			precision;

	padding = mstr->options[6];
	precision = mstr->options[5] > 0 ? mstr->options[5] : 0;
	if (padding && act)
	{
		if (nb < 0 || mstr->options[4] || mstr->options[1])
			padding--;
		n = mstr->size;
		while (n-- && padding > 0)
		{
			padding--;
			precision ? precision-- : 0;
		}
		padding = padding - precision;
		while (padding-- > 0)
			ft_update_buffer(mstr, c);
	}
}

void				ft_conv_int(t_master *mstr)
{
	intmax_t	nb;
	int			*options;

	options = mstr->options;
	nb = ft_fetch_int(mstr);
	mstr->size = ft_int_size_base(nb, 10);
	if (options[5] || ((!options[6] || options[2]) && (mstr->fringe[0])))
	{
		ft_int_padding(mstr, nb, ' ', (!options[0] && (options[5] != -1
						|| !options[3])));
		if (nb < 0)
			ft_update_buffer(mstr, '-');
		else if (options[1])
			ft_update_buffer(mstr, '+');
		else if (options[4] && !options[1] && ((mstr->fringe[0]) || options[6]))
			ft_update_buffer(mstr, ' ');
		ft_int_padding(mstr, nb, '0', !options[0] && options[3]
				&& options[5] == -1);
		ft_buffer_digits_base(mstr, nb < 0 ? -nb : nb, "0123456789");
		ft_int_padding(mstr, nb, ' ', options[0]);
	}
	else
		ft_standard_padding(mstr, ' ');
}
