/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flt_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:29:39 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 16:29:41 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flt_padding(t_printf *mstr, int strlen, char c, int activate)
{
	int		padding;
	int		precision;

	precision = mstr->options[5];
	padding = mstr->options[6];
	if (padding && activate)
	{
		padding -= strlen;
		while (padding-- > 0)
			ft_update_buffer(mstr, c);
	}
}

static int		ft_flt_len(t_printf *mstr, char *flt_ptr)
{
	int *options;
	int flt_len;
	int i;

	flt_len = ft_strlen(flt_ptr);
	options = mstr->options;
	flt_len = flt_ptr[0] != '-' && options[1] ? flt_len + 1 : flt_len;
	flt_len = options[2] && options[5] == 0 ? flt_len + 1 : flt_len;
	flt_len = options[4] && !options[1] && flt_ptr[0] != '-' ?
		flt_len + 1 : flt_len;
	flt_ptr = ft_strchr(flt_ptr, '.');
	if (!flt_ptr)
		return (flt_len);
	i = options[5] + 1;
	while (*flt_ptr++)
		i--;
	flt_len += ft_max(i, 0);
	return (flt_len);
}

static void		ft_point_or_plus(t_printf *mstr, char *flt_ptr, int which)
{
	int *options;

	options = mstr->options;
	if (flt_ptr[0] != '-' && options[1] && which == 1)
		ft_update_buffer(mstr, '+');
	if (options[4] && !options[1] && flt_ptr[0] != '-' && which == 1)
		ft_update_buffer(mstr, ' ');
	if (options[2] && options[5] == 0 && which == 2)
		ft_update_buffer(mstr, '.');
}

static void		ft_print_extraprecision(t_printf *mstr, char *flt_ptr)
{
	int *options;
	int precision;
	int i;

	options = mstr->options;
	precision = options[5] + 1;
	i = 0;
	while (flt_ptr[i] && flt_ptr[i] != '.')
	{
		options[8] == 19 ?
			ft_update_buffer(mstr, ft_toupper(flt_ptr[i])) :
			ft_update_buffer(mstr, flt_ptr[i]);
		i++;
	}
	if (!(flt_ptr[i]))
		return ;
	while (precision--)
		flt_ptr[i] != 'e' && flt_ptr[i] ? ft_update_buffer(mstr, flt_ptr[i++]) :
			ft_update_buffer(mstr, '0');
	while (flt_ptr[i])
		options[8] == 19 ?
			ft_update_buffer(mstr, ft_toupper(flt_ptr[i++])) :
			ft_update_buffer(mstr, flt_ptr[i++]);
}

void			ft_conv_flt_e(t_printf *mstr)
{
	double		dbl;
	long double	ldbl;
	int			strlen;
	int			*options;
	char		*flt_ptr;

	flt_ptr = mstr->flt_str;
	options = mstr->options;
	ft_fetch_flt(mstr, &dbl, &ldbl);
	(mstr->options)[7] == 3 ?
		ft_ftoa_ldbl(flt_ptr, ldbl, options[5], 1) :
		ft_ftoa_dbl(flt_ptr, dbl, options[5], 1);
	strlen = ft_flt_len(mstr, flt_ptr);
	ft_point_or_plus(mstr, flt_ptr, options[3] ? 1 : 0);
	options[3] ? ft_flt_padding(mstr, strlen, '0', !options[0]) :
		ft_flt_padding(mstr, strlen, ' ', !options[0]);
	ft_point_or_plus(mstr, flt_ptr, !options[3] ? 1 : 0);
	ft_print_extraprecision(mstr, flt_ptr);
	ft_point_or_plus(mstr, flt_ptr, 2);
	ft_flt_padding(mstr, strlen, ' ', options[0]);
}
