/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:53:16 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/16 18:54:35 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnjoin(char *d, const char *s, size_t n, int tofree)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*out;

	i = -1;
	j = -1;
	if ((!(len = 0) && !d && !s) || !d)
		return (NULL);
	if (!(out = 0) && !s)
		return (d);
	len = n + ft_strlen(d);
	if (!(out = ft_strnew(len)))
		return (NULL);
	while (d[++i] != '\0')
		out[i] = d[i];
	while (++j < n)
		out[i + j] = s[j];
	if (tofree)
		free(d);
	return (out);
}
