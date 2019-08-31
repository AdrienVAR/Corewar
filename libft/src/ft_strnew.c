/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 06:32:15 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/19 09:40:01 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*out;

	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(out, size + 1);
	return (out);
}
