/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 05:33:42 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/09 14:39:58 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dchar;
	const unsigned char *schar;

	i = 0;
	dchar = (unsigned char *)dst;
	schar = (const unsigned char*)src;
	while (i < n)
	{
		dchar[i] = schar[i];
		if (schar[i] == (unsigned char)c)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
