/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_strsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 08:45:00 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/13 15:34:49 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tab_strsort(char **tab, int (*f)(const char *, const char *))
{
	int		i;

	i = 0;
	while (tab[i + 1])
	{
		if ((*f)(tab[i + 1], tab[i]) < 0)
		{
			ft_strswap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
