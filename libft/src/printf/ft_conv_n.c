/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:26:58 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/04 09:28:05 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_conv_n(t_master *mstr)
{
	intmax_t *nb;

	nb = ft_fetch_int_adr(mstr);
	if (nb)
		*nb = mstr->returnval;
}
