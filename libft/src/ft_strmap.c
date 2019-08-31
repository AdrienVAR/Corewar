/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 07:21:28 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/12 06:59:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(fresh = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (&s[i] && s[i] && f)
	{
		fresh[i] = (*f)(s[i]);
		i++;
	}
	return (fresh);
}
