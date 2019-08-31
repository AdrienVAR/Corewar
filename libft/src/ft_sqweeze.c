/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqweeze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:26:53 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/23 11:13:25 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_tabinit(size_t *i, int tab[4], size_t n)
{
	*i = -1;
	tab[0] = n;
	tab[1] = 0;
	tab[2] = n;
	tab[3] = 0;
}

static void		ft_tabupdate(int tab[4], size_t i, size_t j)
{
	tab[1] = ft_max(i, tab[1]);
	tab[0] = ft_min(i, tab[0]);
	tab[3] = ft_max(j, tab[3]);
	tab[2] = ft_min(j, tab[2]);
}

static char		**ft_fill_output(int tab[4], char **src)
{
	char	**out;
	int		h_sq;
	int		w_sq;
	int		i;

	i = -1;
	if ((tab[1] < tab[0]) || (tab[3] < tab[2]))
		return (NULL);
	h_sq = tab[1] - tab[0] + 1;
	w_sq = tab[3] - tab[2] + 1;
	if (!(out = (char **)malloc(sizeof(char *) * h_sq + 1)))
		return (NULL);
	out[h_sq] = NULL;
	while (++i < h_sq)
	{
		if (!(out[i] = ft_strnew(w_sq)))
			return (NULL);
		ft_strncpy(out[i], &src[i + tab[0]][tab[2]], w_sq);
	}
	return (out);
}

char			**ft_sqweeze(char **src, char c, size_t w, size_t h)
{
	size_t	i;
	size_t	j;
	int		border[4];

	ft_tabinit(&i, border, h);
	while (src[++i])
	{
		j = -1;
		while (src[i][++j])
		{
			if (i >= h || j >= w)
			{
				return (NULL);
			}
			if (src[i][j] != c)
				ft_tabupdate(border, i, j);
		}
		if (j != w)
			return (NULL);
	}
	if (i != h)
		return (NULL);
	return (ft_fill_output(border, src));
}
