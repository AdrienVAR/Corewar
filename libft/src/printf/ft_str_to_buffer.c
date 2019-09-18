/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:14:47 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:31:08 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_str_to_buffer(t_printf *mstr, char *str)
{
	if (!str)
		return ;
	while (*str)
		ft_update_buffer(mstr, *(str++));
}
