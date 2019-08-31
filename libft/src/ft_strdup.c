/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 08:40:02 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/09 14:20:24 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*out;
	int		l;
	int		i;

	i = 0;
	out = 0;
	l = ft_strlen(s1);
	if (!(out = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
