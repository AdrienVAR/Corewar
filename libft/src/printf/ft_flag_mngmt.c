/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_mngmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:02:26 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/24 12:02:43 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		(*g_stat_dico_conv[DICO_CONV_SIZE])() =
{&ft_conv_percent, &ft_conv_int, &ft_conv_int, &ft_conv_str, &ft_conv_ptr,
	&ft_conv_u_int, &ft_conv_u_int, &ft_conv_u_int, &ft_conv_u_int,
	&ft_conv_u_int, &ft_conv_char, &ft_conv_char, &ft_conv_str,
	&ft_conv_int, &ft_conv_u_int, &ft_conv_flt, &ft_conv_flt,
	&ft_conv_flt_e, &ft_conv_flt_e, &ft_conv_flt_g, &ft_conv_flt_g,
	&ft_conv_color, &ft_conv_u_int, &ft_conv_u_int, &ft_conv_np_str,
	&ft_conv_time, &ft_conv_n};

static void		ft_flag_optn_reset(t_printf *mstr)
{
	int i;

	i = -1;
	while (++i < OPTIONS_SIZE)
		mstr->options[i] = 0;
	mstr->options[5] = -1;
}

void			ft_flag_mngmt(t_printf *mstr)
{
	int *options;

	options = mstr->options;
	(mstr->shuttle)++;
	ft_flag_optn_reset(mstr);
	mstr->shuttle = ft_flag_option_check(mstr->shuttle, mstr);
	options[6] = !options[8] ? options[6] - 1 : options[6];
	if (!options[8] && !options[0])
		ft_standard_padding(mstr, options[3] ? '0' : ' ');
	else if (options[8])
		g_stat_dico_conv[options[8] - 1](mstr);
	else
	{
		if (*(mstr->shuttle))
			ft_update_buffer(mstr, *(mstr->shuttle)++);
		ft_standard_padding(mstr, ' ');
	}
}
