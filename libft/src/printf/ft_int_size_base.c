/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_size_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:21:49 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:15:02 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int				ft_int_size_base(intmax_t nb, int base_sz)
{
	if (!nb)
		return (1);
	return (nb / base_sz ? 1 + ft_int_size_base(nb / base_sz, base_sz) : 1);
}

int				ft_u_int_size_base(uintmax_t nb, int base_sz)
{
	if (!nb)
		return (1);
	return (nb / base_sz ? 1 + ft_int_size_base(nb / base_sz, base_sz) : 1);
}
