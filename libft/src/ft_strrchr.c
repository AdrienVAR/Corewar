/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:11:15 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/09 14:32:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	cchar;
	const char		*sout;

	cchar = (unsigned char)c;
	sout = NULL;
	while (*s)
	{
		if (*s == cchar)
			sout = s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	else
		return ((char *)sout);
}
