/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 08:45:41 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/09 16:49:37 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*fresh;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[i])
	{
		while (s[i + j] == ' ' || s[i + j] == '\n' || s[i + j] == '\t')
			j++;
		if (s[i + j])
			i += j;
		else
			break ;
		j = 0;
		i++;
	}
	if (!(fresh = ft_strnew(i)))
		return (NULL);
	ft_strncpy(fresh, s, i);
	return (fresh);
}
