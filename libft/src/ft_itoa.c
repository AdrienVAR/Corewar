/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:15:00 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/13 06:43:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	nstck;
	size_t		sz;
	char		*fresh;

	sz = 1;
	sz = n < 0 ? sz + 1 : sz;
	if (!(nstck = n))
	{
		if (!(fresh = ft_strnew(2)))
			return (NULL);
		fresh[0] = '0';
		return (fresh);
	}
	while (n /= 10)
		sz++;
	if (!(fresh = ft_strnew(sz)))
		return (NULL);
	if (nstck < 0)
		fresh[0] = '-';
	while (nstck)
	{
		fresh[--sz] = nstck > 0 ? nstck % 10 + '0' : -nstck % 10 + '0';
		nstck /= 10;
	}
	return (fresh);
}
