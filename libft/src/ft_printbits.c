/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:03:58 by cgiron            #+#    #+#             */
/*   Updated: 2018/12/14 14:11:43 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printbits(long long int byte, int size)
{
	long long int	i;
	int				sep;

	sep = size;
	i = 1;
	while (--size)
		i = 2 * i;
	while (i > 0)
	{
		if (byte & i)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i = i >> 1;
		sep--;
		if (i && !(sep % 8))
			write(1, " ", 1);
	}
}
