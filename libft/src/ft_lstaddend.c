/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:30:01 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/05 10:25:07 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstaddend(t_list *lst, void const *content, size_t content_size)
{
	t_list	*lstnew;
	t_list	*lnext;

	if (!lst)
		return (ft_lstnew(content, content_size));
	if (!(lstnew = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
	}
	else
	{
		if (!(lstnew->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(lstnew->content, content, content_size);
		lstnew->content_size = content_size;
	}
	lstnew->next = NULL;
	lnext = lst;
	while (lnext->next)
		lnext = lnext->next;
	lnext->next = lstnew;
	return (lst);
}
