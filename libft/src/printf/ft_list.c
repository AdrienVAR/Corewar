/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:22:36 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:15:34 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void		ft_init_master(t_master *mstr, const char *restrict format)
{
	t_list		*new;

	mstr->shuttle = (char *)format;
	mstr->error = 0;
	new = (void *)malloc(sizeof(t_list));
	if (new)
	{
		new->content_size = 0;
		new->content = (void *)malloc(BUFFER);
		new->next = NULL;
	}
	if (!new || !(new->content))
		mstr->error = 1;
	mstr->buffer = new;
	ft_bzero(mstr->options, OPTIONS_SIZE);
	ft_bzero(mstr->fringe, FRINGE_SIZE);
	mstr->prefix[0] = -1;
	mstr->prefix[1] = 0;
	mstr->returnval = 0;
	mstr->size = 0;
}

void		ft_buffer_grow(t_master *mstr)
{
	t_list *added;
	t_list *buffer;

	buffer = mstr->buffer;
	if (buffer && buffer->content_size < BUFFER - 1)
		return ;
	added = (t_list *)malloc(sizeof(t_list));
	if (added)
	{
		added->content_size = 0;
		added->content = (void *)malloc(BUFFER);
		added->next = NULL;
	}
	if (!added || !(added->content))
		mstr->error = 1;
	if (buffer)
		buffer->next = added;
	mstr->buffer = added;
}

void		ft_update_buffer(t_master *mstr, char c)
{
	char	*segment;
	t_list	*buffer;

	if (mstr->error)
		return ;
	buffer = mstr->buffer;
	ft_buffer_grow(mstr);
	segment = buffer->content;
	segment[(buffer->content_size)++] = c;
	(mstr->returnval)++;
}

void		ft_buffer_del(t_list **buffer)
{
	t_list *stock;

	while (*buffer)
	{
		stock = (*buffer)->next;
		if ((*buffer)->content)
		{
			free((*buffer)->content);
			(*buffer)->content = NULL;
		}
		(*buffer)->content_size = 0;
		free(*buffer);
		*buffer = stock;
	}
}

void		ft_list_print(t_list *buffer, t_master *mstr)
{
	while (buffer)
	{
		if ((write(1, buffer->content, buffer->content_size)) == -1)
		{
			mstr->error = 1;
			break ;
		}
		buffer = buffer->next;
	}
}
