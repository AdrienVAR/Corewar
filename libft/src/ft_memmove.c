/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 06:53:14 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 12:48:06 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dchar;
	const unsigned char	*schar;
	size_t				dec;

	if (!dst && !src)
		return (dst);
	i = 0;
	dchar = (unsigned char *)dst;
	schar = (const unsigned char*)src;
	dec = (int)(dst - src);
	while (i < n)
	{
		if (dec > n || dec <= 0)
			dchar[i] = schar[i];
		else
			dchar[n - i - 1] = schar[n - i - 1];
		i++;
	}
	return (dst);
}
