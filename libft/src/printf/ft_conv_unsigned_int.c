/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_special_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:01:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:29:52 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_u_int_padding(t_printf *mstr, char c, int activation)
{
	intmax_t		n;
	int				padding;
	int				precision;

	precision = mstr->options[5] > 0 ? mstr->options[5] : 0;
	padding = mstr->options[6] - mstr->prefix[1];
	if (padding > 0 && activation)
	{
		n = mstr->size;
		while (n-- && padding-- > 0)
			precision ? precision-- : 0;
		padding = padding - precision;
		while (padding-- > 0)
			ft_update_buffer(mstr, c);
	}
}

static char			*u_base_choice(t_printf *mstr)
{
	int type;

	type = mstr->options[8];
	if (type == TYPE_OC || type == TYPE_CAP_O)
		return ("01234567");
	else if (type == TYPE_BIN || type == TYPE_CAP_BIN)
		return ("01");
	else if (type == TYPE_HEX)
		return ("0123456789abcdef");
	else if (type == TYPE_CAP_HEX)
		return ("0123456789ABCDEF");
	return ("0123456789");
}

static void			ft_set_prefix(t_printf *mstr)
{
	if (mstr->fringe[1] && mstr->options[2])
	{
		if (mstr->options[8] == TYPE_OC && (mstr->prefix[1] = 1))
			mstr->prefix[0] = PRE_OC;
		else if (mstr->options[8] == TYPE_HEX && (mstr->prefix[1] = 2))
			mstr->prefix[0] = PRE_HEX;
		else if (mstr->options[8] == TYPE_CAP_HEX
				&& (mstr->prefix[1] = 2))
			mstr->prefix[0] = PRE_CAP_HEX;
		else if (mstr->options[8] == TYPE_CAP_O
				&& (mstr->prefix[1] = 2))
			mstr->prefix[0] = PRE_CAP_O;
		else if (mstr->options[8] == TYPE_BIN
				&& (mstr->prefix[1] = 2))
			mstr->prefix[0] = PRE_BIN;
		else if (mstr->options[8] == TYPE_CAP_BIN
				&& (mstr->prefix[1] = 2))
			mstr->prefix[0] = PRE_CAP_BIN;
	}
}

void				ft_conv_u_int(t_printf *mstr)
{
	uintmax_t		nb;
	char			*base;
	int				*options;
	int				alignt[2];

	options = mstr->options;
	nb = ft_fetch_u_int(mstr);
	ft_set_prefix(mstr);
	base = u_base_choice(mstr);
	mstr->size = ft_u_int_size_base(nb, ft_strlen(base));
	if (options[5] || (options[2] && ft_prec_zero_pref(options[8])))
	{
		alignt[0] = !options[0] && (!options[3] || options[5] != -1);
		alignt[1] = !options[0] && !(!options[3] || options[5] != -1);
		ft_u_int_padding(mstr, ' ', alignt[0]);
		ft_prefixes(mstr, mstr->prefix[0]);
		ft_u_int_padding(mstr, '0', alignt[1]);
		ft_buffer_digits_base(mstr, nb, base);
		ft_u_int_padding(mstr, ' ', mstr->options[0]);
		ft_prefixes(mstr, PRE_RESET);
	}
	else
		ft_standard_padding(mstr, ' ');
}
