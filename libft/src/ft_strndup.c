/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:28:18 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/23 10:26:11 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*out;
	size_t	i;

	i = 0;
	out = 0;
	if (!(out = ft_strnew(n)))
		return (NULL);
	while (i < n)
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
