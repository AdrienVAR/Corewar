/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 07:33:43 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/09 16:04:38 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;

	i = 0;
	if (!s || !(fresh = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (&s[i] && s[i] && f)
	{
		fresh[i] = (*f)(i, s[i]);
		i++;
	}
	return (fresh);
}
