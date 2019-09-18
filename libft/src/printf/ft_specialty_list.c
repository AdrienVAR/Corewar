/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specialty_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:08:35 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 18:09:49 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_list_sprint(char *str, t_list *buffer, t_printf *mstr)
{
	int i;

	i = 0;
	if (!(str) && (mstr->error = 1))
		return ;
	while (buffer)
	{
		ft_memcpy(str + i, buffer->content, buffer->content_size);
		i += buffer->content_size;
		buffer = buffer->next;
	}
	str[++i] = 0;
}

void		ft_list_asprint(char **str, t_list *buffer, t_printf *mstr)
{
	int i;

	i = 0;
	if (!(str) && (mstr->error = 1))
		return ;
	(*str) = ft_strnew(mstr->returnval);
	if (!(*str) && (mstr->error = 1))
		return ;
	while (buffer)
	{
		ft_memcpy((*str) + i, buffer->content, buffer->content_size);
		i += buffer->content_size;
		buffer = buffer->next;
	}
}

void		ft_list_dprint(int fd, t_list *buffer, t_printf *mstr)
{
	while (buffer)
	{
		if ((write(fd, buffer->content, buffer->content_size)) == -1)
		{
			mstr->error = 1;
			break ;
		}
		buffer = buffer->next;
	}
}
