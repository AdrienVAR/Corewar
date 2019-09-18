/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:24:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:25:15 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_fetch_ptr(t_printf *mstr)
{
	uintmax_t addr;

	addr = (uintmax_t)va_arg(mstr->arg, uintmax_t);
	return (addr);
}
