/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:39:59 by cgiron            #+#    #+#             */
/*   Updated: 2019/04/16 14:05:38 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**ft_split(char const *s, char c, int *sz)
{
	char		*word;
	char		**splitted;
	size_t		wl;

	while (!(wl = 0) && *s == c)
		s++;
	while (!(word = 0) && s[wl] && s[wl] != c)
		wl++;
	(*sz)++;
	if (wl)
	{
		if (!(word = ft_strnew(wl)))
			return (!(sz = 0) ? NULL : NULL);
		ft_strncpy(word, s, wl);
		splitted = ft_split(s + wl, c, sz);
	}
	else
		splitted = (char **)malloc(sizeof(char *) * (*sz));
	if (splitted && (*sz))
		splitted[--(*sz)] = word;
	else
		free(word);
	return (splitted);
}

char			**ft_strsplit(char const *s, char c)
{
	int			sz;

	if (!s)
		return (NULL);
	sz = 0;
	return (ft_split(s, c, &sz));
}
