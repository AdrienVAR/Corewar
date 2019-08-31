/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:28:08 by cgiron            #+#    #+#             */
/*   Updated: 2018/12/07 11:28:11 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**ft_newstrtab(int n)
{
	char	**out;
	int		i;

	i = 0;
	if (!(out = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (i < n)
		out[i++] = NULL;
	out[i] = NULL;
	return (out);
}
