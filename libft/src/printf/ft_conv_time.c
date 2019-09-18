/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:03:48 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:11:39 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_str_padding(t_printf *mstr, int strlen, char c, int act)
{
	int		padding;

	padding = mstr->options[6];
	if (padding && act)
	{
		padding -= strlen;
		while (padding-- > 0)
			ft_update_buffer(mstr, c);
	}
}

static void		ft_year_month_day(uintmax_t t, int ymd[3])
{
	uintmax_t var[6];

	t = t / (60 * 60 * 24);
	if (t < 1)
		t = 0;
	var[0] = (uint32_t)((4 * t + 102032) / 146097 + 15);
	var[1] = (uint32_t)(t + 2442113 + var[0] - (var[0] / 4));
	var[2] = (20 * var[1] - 2442) / 7305;
	var[3] = var[1] - 365 * var[2] - (var[2] / 4);
	var[4] = var[3] * 1000 / 30601;
	var[5] = var[3] - var[4] * 30 - var[4] * 601 / 1000;
	if (var[4] <= 13)
	{
		var[2] -= 4716;
		var[4] -= 1;
	}
	else
	{
		var[2] -= 4715;
		var[4] -= 13;
	}
	ymd[0] = var[2];
	ymd[1] = var[4];
	ymd[2] = var[5];
}

int				ft_time_length(t_printf *mstr)
{
	int size;

	size = mstr->options[7];
	if (size == 4)
		return (4);
	else if (size == 1)
		return (7);
	else
		return (10);
}

void			ft_write_component(t_printf *mstr, int comp, int size)
{
	if (size == 4)
	{
		ft_update_buffer(mstr, comp / 1000 + '0');
		ft_update_buffer(mstr, comp % 1000 / 100 + '0');
	}
	else
		ft_update_buffer(mstr, '-');
	ft_update_buffer(mstr, comp % 100 / 10 + '0');
	ft_update_buffer(mstr, comp % 10 + '0');
}

void			ft_conv_time(t_printf *mstr)
{
	uintmax_t	time;
	int			ymd[3];
	int			strlen;
	int			*options;

	options = mstr->options;
	time = ft_fetch_time(mstr);
	ft_year_month_day(time, ymd);
	strlen = ft_time_length(mstr);
	options[3] ? ft_str_padding(mstr, strlen, '0', !options[0]) :
		ft_str_padding(mstr, strlen, ' ', !options[0]);
	ft_write_component(mstr, ymd[0], 4);
	if (options[7] != 4)
	{
		ft_write_component(mstr, ymd[1], 2);
		if (options[7] != 1)
			ft_write_component(mstr, ymd[2], 2);
	}
	ft_str_padding(mstr, strlen, ' ', options[0]);
}
