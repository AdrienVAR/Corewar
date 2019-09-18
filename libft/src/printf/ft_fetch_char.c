/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:24:26 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:24:43 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fetch_char(t_master *mstr, wint_t *chrl, char *chr)
{
	int size;
	int temp;

	size = mstr->options[7];
	if (size == 2 || mstr->options[8] == TYPE_CAP_C)
		*chrl = (wint_t)va_arg(mstr->arg, wint_t);
	else
	{
		temp = (int)va_arg(mstr->arg, int);
		*chr = (char)temp;
	}
}
