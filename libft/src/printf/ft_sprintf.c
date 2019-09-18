/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 07:18:30 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 16:17:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_sip_through(t_master *mstr)
{
	char *shuttle;

	shuttle = mstr->shuttle;
	while (*shuttle && *shuttle != '%')
	{
		ft_update_buffer(mstr, *shuttle);
		shuttle++;
	}
	return (shuttle);
}

int				ft_sprintf(char *str, const char *restrict format, ...)
{
	t_master	mstr_val;
	t_master	*mstr;
	t_list		*depart;

	mstr = &mstr_val;
	ft_init_master(mstr, format);
	depart = mstr->buffer;
	va_start(mstr->arg, format);
	while ((mstr->shuttle = ft_sip_through(mstr))
			&& *(mstr->shuttle) == '%')
		ft_flag_mngmt(mstr);
	if (!(mstr->error))
		ft_list_sprint(str, depart, mstr);
	ft_buffer_del(&depart);
	va_end(mstr->arg);
	return (!(mstr->error) ? mstr->returnval : -1);
}
