/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:46:03 by cgiron            #+#    #+#             */
/*   Updated: 2018/12/17 10:14:42 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_percent_padding(t_printf *mstr, char c, int activate)
{
	int			padding;

	padding = mstr->options[6];
	if (--padding && activate)
	{
		while (padding-- > 0)
			ft_update_buffer(mstr, c);
	}
}

void				ft_conv_percent(t_printf *mstr)
{
	int			*options;

	options = mstr->options;
	options[3] ? ft_percent_padding(mstr, '0', !options[0]) :
		ft_percent_padding(mstr, ' ', !options[0]);
	ft_update_buffer(mstr, '%');
	ft_percent_padding(mstr, ' ', options[0]);
}
