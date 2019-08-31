/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:00:02 by cgiron            #+#    #+#             */
/*   Updated: 2019/04/16 14:09:35 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**ft_whitespace(char const *s, int *sz)
{
	char		*word;
	char		**splitted;
	size_t		wl;

	while (!(wl = 0) && ((*s >= 8 && *s <= 13) || *s == 32))
		s++;
	while (!(word = 0) && s[wl] && ((s[wl] < 8 || s[wl] > 13) && s[wl] != 32))
		wl++;
	(*sz)++;
	if (wl)
	{
		if (!(word = ft_strnew(wl)))
			return (!(sz = 0) ? NULL : NULL);
		ft_strncpy(word, s, wl);
		splitted = ft_whitespace(s + wl, sz);
	}
	else
		splitted = (char **)malloc(sizeof(char *) * (*sz));
	if (splitted && (*sz))
		splitted[--(*sz)] = word;
	else
		free(word);
	return (splitted);
}

char			**ft_split_whitespace(char const *s)
{
	int			sz;

	if (!s)
		return (NULL);
	sz = 0;
	return (ft_whitespace(s, &sz));
}
