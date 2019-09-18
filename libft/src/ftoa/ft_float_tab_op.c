/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_tab_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:18:08 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/23 12:18:09 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"

int			ft_div_tab(int **num, int divider, int len, t_lli base)
{
	t_lli	temp;
	t_lli	remainder;
	t_lli	i;
	int		*tab;

	i = -1;
	tab = *num;
	remainder = 0;
	while (++i < len)
	{
		temp = (t_lli)tab[i];
		tab[i] = (int)((remainder * base + temp) / divider);
		remainder = (remainder * base + temp) % divider;
	}
	if (remainder)
		return (0);
	return (1);
}

int			ft_add_tab(int **num, int *add, int len, t_lli base)
{
	t_lli	temp;
	t_lli	remainder;
	t_lli	i;
	int		*tab;

	i = len;
	tab = *num;
	remainder = 0;
	while (--i >= 0)
	{
		temp = (t_lli)tab[i];
		tab[i] = (int)((remainder + temp + add[i]) % base);
		remainder = (remainder + temp + add[i]) / base;
	}
	if (remainder)
		return (0);
	return (1);
}

int			ft_mult_tab(int **num, int multiplier, int len, t_lli base)
{
	t_lli	temp;
	t_lli	remainder;
	t_lli	i;
	int		*tab;

	i = len;
	tab = *num;
	remainder = 0;
	while (--i)
	{
		temp = (t_lli)tab[i];
		tab[i] = (int)((remainder + temp * multiplier) % base);
		remainder = (remainder + temp * multiplier) / base;
	}
	if (remainder)
		return (0);
	return (1);
}
