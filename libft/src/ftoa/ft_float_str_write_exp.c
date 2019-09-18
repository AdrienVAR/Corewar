/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_str_write_exp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:57:27 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 14:57:31 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"

void			ft_float_str_write_exp(char *str, int exp, int act)
{
	if (!act || !str)
		return ;
	while (*str)
		str++;
	*str = 'e';
	str++;
	if (exp < 0 && (exp = -exp))
		*(str++) = '-';
	else
		*(str++) = '+';
	if (exp > 10000)
		*(str++) = '0' + exp % 100000 / 10000;
	if (exp > 1000)
		*(str++) = '0' + exp % 10000 / 1000;
	if (exp > 100)
		*(str++) = '0' + exp % 1000 / 100;
	*(str++) = '0' + exp % 100 / 10;
	*(str++) = '0' + exp % 10;
}
