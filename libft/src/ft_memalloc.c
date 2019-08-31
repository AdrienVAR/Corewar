/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 06:15:20 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/28 06:47:04 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*outptr;

	if (!(outptr = (void *)malloc(size)))
		return (NULL);
	ft_memset(outptr, 0, size);
	return (outptr);
}
