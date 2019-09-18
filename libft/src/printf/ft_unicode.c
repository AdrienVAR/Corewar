/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:15:05 by cgiron            #+#    #+#             */
/*   Updated: 2018/12/17 11:46:52 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unichar_length(int uni)
{
	if (uni <= 0x7f)
		return (1);
	else if (uni <= 0x7ff)
		return (2);
	else if (uni <= 0xffff)
		return (3);
	else
		return (4);
}

void		ft_add_uni_buffer(t_master *mstr, wchar_t uni)
{
	char	unistr[5];
	int		unisz;

	unisz = ft_unichar_length(uni);
	unistr[0] = unisz == 1 ? (uni) : ((uni & 0x3f) | 0x80);
	uni = uni >> 6;
	unistr[1] = unisz == 2 ? ((uni & 0x1f) | 0xC0) : ((uni & 0x3f) | 0x80);
	uni = uni >> 6;
	unistr[2] = unisz == 3 ? ((uni & 0xf) | 0xE0) : ((uni & 0x3f) | 0x80);
	uni = uni >> 6;
	unistr[3] = unisz == 4 ? ((uni & 0x7) | 0xF0) : ((uni & 0x3f) | 0x80);
	while (unisz--)
		ft_update_buffer(mstr, unistr[unisz]);
}
