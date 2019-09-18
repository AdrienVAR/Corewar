/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_str_remove_dot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:54:52 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:21:06 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

void		ft_float_str_remove_dot(char *str_out, int act)
{
	char	*ptr;
	int		tail_size;

	ptr = ft_strchr(str_out, '.');
	if (!act || !ptr)
		return ;
	tail_size = ptr + 1 - str_out;
	ft_memmove(ptr, ptr + 1, MAX_STR_SZ - tail_size);
	str_out[MAX_STR_SZ - 1] = 0;
}
