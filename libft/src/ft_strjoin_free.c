/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:33:39 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/02 11:48:08 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strleni(char *src)
{
	int i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char		*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if ((str = (char *)malloc(sizeof(char) * (ft_strleni(s1)
		+ ft_strleni(s2)) + 1)) == NULL)
	{
		ft_strdel(&s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i++] = '\n';
	str[i] = '\0';
	ft_strdel(&s1);
	return (str);
}
