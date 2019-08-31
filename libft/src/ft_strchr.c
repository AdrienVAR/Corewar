/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:50:15 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/09 14:24:57 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cchar;

	cchar = (unsigned char)c;
	while (*s)
	{
		if (*s == cchar)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	else
		return (NULL);
}
