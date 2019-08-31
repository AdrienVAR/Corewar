/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 07:55:38 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/09 16:50:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*fresh;
	const char	*d;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	d = s + start;
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		fresh[i] = d[i];
		i++;
	}
	return (fresh);
}
