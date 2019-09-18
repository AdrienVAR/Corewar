/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:34:15 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:29:19 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_str_padding(t_master *mstr, int strlen, char c, int activate)
{
	int		padding;
	int		precision;

	precision = mstr->options[5];
	padding = mstr->options[6];
	if (padding && activate)
	{
		precision = precision == -1 ? strlen : precision;
		padding -= precision < strlen ? precision : strlen;
		while (padding-- > 0)
			ft_update_buffer(mstr, c);
	}
}

static int		ft_strl_length(char *str, wchar_t *strl, int precision)
{
	int len;
	int i;
	int clen;

	i = -1;
	len = 0;
	if (str)
		len = ft_strlen(str);
	else
	{
		while (strl[++i])
		{
			clen = ft_unichar_length(strl[i]);
			if (precision < 0 || (len + clen) <= precision)
				len += clen;
			else
				break ;
		}
	}
	return (len);
}

static void		ft_null_str(t_master *mstr)
{
	int		padding;
	int		precision;
	char	*nope;
	int		*options;

	options = mstr->options;
	nope = "(null)";
	precision = options[5] <= 6 ? options[5] : 6;
	padding = precision >= 0 ? options[6] - precision : options[6];
	padding = precision < 0 ? padding - 6 : padding;
	while (padding > 0 && !(options[0]))
	{
		padding--;
		options[3] ? ft_update_buffer(mstr, '0') :
			ft_update_buffer(mstr, ' ');
	}
	while (precision-- && *nope)
		ft_update_buffer(mstr, *nope++);
	while (padding-- > 0 && (options[0]))
		ft_update_buffer(mstr, ' ');
}

void			ft_conv_str(t_master *mstr)
{
	wchar_t		*strl;
	char		*str;
	int			strlen;
	int			precision;
	int			*options;

	str = NULL;
	strl = NULL;
	options = mstr->options;
	precision = options[5];
	ft_fetch_str(mstr, &strl, &str);
	if (!mstr->fringe[2])
	{
		strlen = ft_strl_length(str, strl, precision);
		options[3] ? ft_str_padding(mstr, strlen, '0', !options[0]) :
			ft_str_padding(mstr, strlen, ' ', !options[0]);
		while (str && *str && precision--)
			ft_update_buffer(mstr, *str++);
		precision = precision < 0 ? strlen : precision;
		while (strl && *strl && (precision -= ft_unichar_length(*strl)) >= 0)
			ft_add_uni_buffer(mstr, *strl++);
		ft_str_padding(mstr, strlen, ' ', options[0]);
	}
	else
		ft_null_str(mstr);
}
