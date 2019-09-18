/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:07:53 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:07:06 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_init_color_text(t_master *mstr)
{
	int	*options;

	options = mstr->options;
	if (options[6] == 1)
		ft_str_to_buffer(mstr, "30");
	if (options[6] == 2)
		ft_str_to_buffer(mstr, "31");
	if (options[6] == 3)
		ft_str_to_buffer(mstr, "32");
	if (options[6] == 4)
		ft_str_to_buffer(mstr, "33");
	if (options[6] == 5)
		ft_str_to_buffer(mstr, "34");
	if (options[6] == 6)
		ft_str_to_buffer(mstr, "35");
	if (options[6] == 7)
		ft_str_to_buffer(mstr, "36");
	if (options[6] == 8)
		ft_str_to_buffer(mstr, "37");
	if (options[6] && (options[5] || options[7]))
		ft_update_buffer(mstr, ';');
}

static void			ft_init_color_background(t_master *mstr)
{
	int	*options;

	options = mstr->options;
	if (options[5] == 1)
		ft_str_to_buffer(mstr, "40");
	if (options[5] == 2)
		ft_str_to_buffer(mstr, "41");
	if (options[5] == 3)
		ft_str_to_buffer(mstr, "42");
	if (options[5] == 4)
		ft_str_to_buffer(mstr, "43");
	if (options[5] == 5)
		ft_str_to_buffer(mstr, "44");
	if (options[5] == 6)
		ft_str_to_buffer(mstr, "45");
	if (options[5] == 7)
		ft_str_to_buffer(mstr, "46");
	if (options[5] == 8)
		ft_str_to_buffer(mstr, "47");
	if (options[5] && options[7])
		ft_update_buffer(mstr, ';');
}

static void			ft_init_style(t_master *mstr)
{
	int	*options;

	options = mstr->options;
	if (options[7] == 1 || options[7] == 4)
		ft_str_to_buffer(mstr, "1");
	if (options[7] == 2 || options[7] == 5)
		ft_str_to_buffer(mstr, "4");
	if (options[7] == 3)
		ft_str_to_buffer(mstr, "5");
	if (options[7] == 6)
		ft_str_to_buffer(mstr, "7");
	if (options[7] == 7)
		ft_str_to_buffer(mstr, "8");
}

void				ft_conv_color(t_master *mstr)
{
	int *options;

	options = mstr->options;
	if (options[2] || (!options[7] && !options[6] && !options[5]))
		ft_str_to_buffer(mstr, "\033[0m");
	else
	{
		ft_str_to_buffer(mstr, "\033[");
		ft_init_color_text(mstr);
		ft_init_color_background(mstr);
		ft_init_style(mstr);
		ft_update_buffer(mstr, 'm');
	}
}
