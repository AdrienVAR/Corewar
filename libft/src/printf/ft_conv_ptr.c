/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:07:16 by cgiron            #+#    #+#             */
/*   Updated: 2018/12/17 10:16:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_ptr_padding(t_printf *mstr, char c, int activate)
{
	int			padding;
	int			precision;
	int			n;
	int			*options;

	options = mstr->options;
	precision = options[5] > 0 ? options[5] : 0;
	padding = options[6] - mstr->prefix[1];
	if (padding > 0 && activate)
	{
		n = mstr->size;
		while (n-- && padding-- > 0)
			precision ? precision-- : 0;
		padding = padding - precision;
		while (padding-- > 0)
			ft_update_buffer(mstr, c);
	}
}

void				ft_conv_ptr(t_printf *mstr)
{
	uintmax_t	addr;
	int			*options;
	int			alignt[2];

	options = mstr->options;
	mstr->prefix[0] = PRE_PTR;
	mstr->prefix[1] = 2;
	addr = ft_fetch_ptr(mstr);
	alignt[0] = !options[0] && (!options[3] || options[5] != -1);
	alignt[1] = !options[0] && !(!options[3] || options[5] != -1);
	mstr->size = ft_int_size_base(addr, 16);
	ft_ptr_padding(mstr, ' ', alignt[0]);
	ft_prefixes(mstr, mstr->prefix[0]);
	ft_ptr_padding(mstr, '0', alignt[1]);
	if (options[5] || options[6])
		ft_buffer_digits_base(mstr, addr, "0123456789abcdef");
	ft_ptr_padding(mstr, ' ', options[0]);
	ft_prefixes(mstr, PRE_RESET);
}
