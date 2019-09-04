/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:30:01 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/04 14:15:41 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstaddend(t_list *lst, void const *content, size_t content_size)
{
	t_list	*lstnew;
	t_list	*lnext;

	if (!(lstnew = ft_lstnew(content, content_size)))
		return (NULL);
	if (!lst)
		return (lstnew);
	lnext = lst;
	while (lnext->next)
		lnext = lnext->next;
	lnext->next = lstnew;
	return (lst);
}
