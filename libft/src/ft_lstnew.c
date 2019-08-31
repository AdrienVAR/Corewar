/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 05:41:07 by cgiron            #+#    #+#             */
/*   Updated: 2019/04/16 14:28:45 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	if (!(lstnew = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
	}
	else
	{
		if (!(lstnew->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(lstnew->content, content, content_size);
		lstnew->content_size = content_size;
	}
	lstnew->next = NULL;
	return (lstnew);
}
