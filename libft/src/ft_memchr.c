/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 06:56:00 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/09 14:15:53 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char *schar;
	unsigned char		cchar;

	i = 0;
	schar = (const unsigned char*)s;
	cchar = (unsigned char)c;
	while (i < n)
	{
		if (schar[i] == cchar)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}
