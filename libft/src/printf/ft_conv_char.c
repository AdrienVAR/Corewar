/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:34:15 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:04:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_char_padding(t_master *mstr, char c, int act, int c_len)
{
	int			padding;

	padding = mstr->options[6] - c_len;
	if (padding && act)
	{
		while (padding-- > 0)
			ft_update_buffer(mstr, c);
	}
}

void				ft_conv_char(t_master *mstr)
{
	wint_t			chrl;
	char			chr;
	int				*options;
	int				c_len;

	options = mstr->options;
	ft_fetch_char(mstr, &chrl, &chr);
	c_len = options[7] == 2 || mstr->options[8] == TYPE_CAP_C ?
	ft_unichar_length(chrl) : 1;
	options[3] ? ft_char_padding(mstr, '0', !options[0], c_len) :
		ft_char_padding(mstr, ' ', !options[0], c_len);
	if (options[7] == 2 || mstr->options[8] == TYPE_CAP_C)
		ft_add_uni_buffer(mstr, chrl);
	else
		ft_update_buffer(mstr, chr);
	ft_char_padding(mstr, ' ', options[0], c_len);
}
