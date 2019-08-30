/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:09:53 by gdrai             #+#    #+#             */
/*   Updated: 2019/08/30 15:10:07 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	int		len;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strleni(s1) + ft_strleni(s2);
	if ((str = (char *)malloc(sizeof(char) * len + 2)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i++] = '\n';
	str[i] = '\0';
	if (s1)
		ft_strdel(&s1);
	return (str);
}
