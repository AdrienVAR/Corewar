/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:58:24 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:21:46 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

int		ft_putnbr_str(char *str, int nbr, int szmax)
{
	int i;
	int ns;
	int	base_sz;

	base_sz = REDUCE_WRK_BASE;
	i = -1;
	while (++i < base_sz - szmax && szmax > 0)
		;
	if (szmax < 0)
	{
		base_sz = 1;
		ns = nbr;
		while (ns /= 10)
			base_sz++;
	}
	while (i < base_sz)
	{
		ns = (nbr / ft_power(10, i)) % 10;
		str[base_sz - i++ - 1] = '0' + ns;
	}
	return (szmax < 0 ? base_sz : szmax);
}
