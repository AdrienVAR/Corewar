/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_prefixes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:10:11 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:31:30 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_prec_zero_pref(int type)
{
	if (type == TYPE_CAP_HEX)
		return (1);
	else if (type == TYPE_OC)
		return (1);
	else if (type == TYPE_CAP_O)
		return (1);
	return (0);
}

void			ft_prefixes(t_master *mstr, int prefix)
{
	if (prefix == PRE_RESET || mstr->prefix[0] == -1)
	{
		mstr->prefix[0] = -1;
		mstr->prefix[1] = 0;
		return ;
	}
	ft_update_buffer(mstr, '0');
	if (prefix == PRE_CAP_HEX)
		ft_update_buffer(mstr, 'X');
	else if (prefix == PRE_HEX)
		ft_update_buffer(mstr, 'x');
	else if (prefix == PRE_CAP_BIN)
		ft_update_buffer(mstr, 'B');
	else if (prefix == PRE_BIN)
		ft_update_buffer(mstr, 'b');
	else if (prefix == PRE_PTR)
		ft_update_buffer(mstr, 'x');
}
