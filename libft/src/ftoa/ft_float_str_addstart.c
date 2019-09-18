/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_str_addstart.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:48:16 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:20:39 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"
#include "libft.h"

void		ft_float_str_addstart(char *str, int act, char c)
{
	if (!act || !str)
		return ;
	ft_memmove(str + 1, str, MAX_STR_SZ - 1);
	str[0] = c;
}
