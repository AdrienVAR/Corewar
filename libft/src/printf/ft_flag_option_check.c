/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_option_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:09:53 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/24 12:09:55 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flag_conv_opt_cmp(char needle, char *activ)
{
	char *found;

	found = ft_strchr(activ, needle);
	return (found ? (int)(found - activ) : -1);
}

static char		*ft_extract_nb(char *navette, int *value, t_master *mstr)
{
	*value = 0;
	if (*navette >= '0' && *navette <= '9')
	{
		while (*navette >= '0' && *navette <= '9')
		{
			*value = *value * 10 + *navette - '0';
			navette++;
		}
	}
	else if (*navette == '*')
	{
		*value = (int)va_arg(mstr->arg, int);
		*value = *value < 0 ? -1 : *value;
		navette++;
	}
	return (--navette);
}

static int		ft_flag_size_val(char mark, int actualval)
{
	if (mark == 'j' || actualval == 6)
		actualval = 6;
	else if (mark == 'z' || actualval == 7)
		actualval = 7;
	else if (mark == 'L' || actualval == 3)
		actualval = 3;
	else if (mark == 'l' || actualval == 2 || actualval == 5)
		actualval = actualval == 2 || actualval == 5 ? 5 : 2;
	else if (mark == 'h')
		actualval = actualval == 1 || actualval == 4 ? 4 : 1;
	return (actualval);
}

static void		ft_flag_star_extract(t_master *mstr)
{
	mstr->options[6] = (int)va_arg(mstr->arg, int);
	mstr->options[0] = mstr->options[6] < 0 ? 1 : 0;
	mstr->options[6] = ft_abs(mstr->options[6]);
}

char			*ft_flag_option_check(char *navette, t_master *mstr)
{
	int		dec;

	while (*navette && (dec = ft_flag_conv_opt_cmp(*navette, OPTION_LST)) != -1)
	{
		if (dec <= 4)
			mstr->options[dec] = 1;
		else if (*navette == '.')
			navette = ft_extract_nb(++navette, &(mstr->options[5]), mstr);
		else if (*navette >= '1' && *navette <= '9')
			navette = ft_extract_nb(navette, &(mstr->options[6]), mstr);
		else if (*navette == '*')
			ft_flag_star_extract(mstr);
		else if (ft_strchr(SIZE_LST, *navette))
			mstr->options[7] = ft_flag_size_val(*navette, mstr->options[7]);
		navette++;
	}
	if (*navette && (dec = ft_flag_conv_opt_cmp(*navette, CONVERSION)) != -1)
	{
		mstr->options[8] = dec + 1;
		navette++;
	}
	return (navette);
}
