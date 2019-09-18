/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_output_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:39:49 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:20:30 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

static void		ft_zero_dot_init(t_flt_mstr *mflt, char *str, int which_g)
{
	int prec;
	int sci;
	int e_exp;

	prec = mflt->precision;
	sci = mflt->science;
	e_exp = mflt->e_exp;
	ft_float_str_remove_leading_zero(str, sci == 1, e_exp);
	ft_float_str_remove_leading_zero(str, !which_g, e_exp);
	ft_float_str_insert_dot(str, 1, sci == 1 && prec != 1);
	ft_float_str_insert_dot(str,
			e_exp < prec ? ft_max(e_exp, 0) + 1 : 1,
			sci == 2);
	ft_float_str_remove_trailing_zero(str, sci == 2 || prec == 0);
}

void			ft_float_output_str(t_flt_mstr *mflt)
{
	int	which_g;

	ft_float_write_str(mflt->str_out, mflt);
	mflt->precision += mflt->science == 1 ? 1 : 0;
	if (!(mflt->science))
	{
		ft_float_rounder(mflt->str_out, ft_max(mflt->precision, 0));
		ft_float_str_remove_dot(mflt->str_out, !(mflt->precision));
	}
	if (mflt->science)
	{
		ft_float_extract_e_exp(mflt, mflt->str_out);
		ft_float_str_remove_dot(mflt->str_out, 1);
		ft_float_g_rounder(mflt, mflt->str_out, ft_max(mflt->precision, 1));
		which_g = ((mflt->e_exp >= -4 && mflt->e_exp < 0)
				|| (mflt->e_exp < mflt->precision && mflt->e_exp >= 0))
			&& mflt->science == 2;
		ft_zero_dot_init(mflt, mflt->str_out, which_g);
		ft_float_str_write_exp(mflt->str_out,
				mflt->e_exp, !which_g || mflt->science == 1);
	}
	ft_float_str_addstart(mflt->str_out, mflt->sign != 0, '-');
}
