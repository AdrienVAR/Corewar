/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:19:48 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/14 10:11:49 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_concat(char *dest, const char *source, int n)
{
	unsigned int i;

	i = 0;
	while (source[i])
	{
		if (n > 1)
		{
			*dest++ = source[i];
			n--;
		}
		i++;
	}
	*dest = '\0';
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	dlen;
	size_t	realdlen;
	char	*d;

	n = size;
	dlen = 0;
	realdlen = 0;
	while (dlen < size && dst[dlen])
		dlen++;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	realdlen = ft_strlen(dst);
	d = dst + realdlen;
	ft_concat(d, src, n);
	return (dlen + ft_strlen(src));
}
