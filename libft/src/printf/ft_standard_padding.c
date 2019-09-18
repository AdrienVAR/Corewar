/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_standard_padding.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:29:34 by cgiron            #+#    #+#             */
/*   Updated: 2018/12/17 10:30:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_standard_padding(t_master *mstr, char c)
{
	int			padding;

	padding = mstr->options[6];
	while (padding-- > 0)
		ft_update_buffer(mstr, c);
}
