/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_str_insert_dot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:36:17 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:20:56 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

void		ft_float_str_insert_dot(char *str_out, int pos, int act)
{
	if (!act || !str_out || pos < 0 || pos >= MAX_STR_SZ)
		return ;
	ft_memmove(str_out + (pos + 1), str_out + pos, MAX_STR_SZ - (pos + 1));
	str_out[pos] = '.';
}
