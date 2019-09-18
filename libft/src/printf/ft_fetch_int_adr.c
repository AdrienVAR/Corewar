/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_int_adr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:24:52 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/04 09:24:53 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	*ft_fetch_int_adr(t_master *mstr)
{
	return ((intmax_t *)va_arg(mstr->arg, intmax_t *));
}
