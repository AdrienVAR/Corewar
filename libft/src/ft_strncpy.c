/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:55:36 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/16 14:08:10 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	len++;
	i = -1;
	if (len == 0)
		return (dst);
	while (src[++i] && --len > 0)
		dst[i] = src[i];
	if (len)
		ft_bzero(dst + i, len - 1);
	return (dst);
}
