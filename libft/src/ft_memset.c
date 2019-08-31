/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:25:02 by cgiron            #+#    #+#             */
/*   Updated: 2018/12/07 11:25:09 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	l;
	size_t			i;
	unsigned char	*bchar;

	bchar = (unsigned char *)b;
	l = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*bchar++ = l;
		i++;
	}
	return (b);
}
