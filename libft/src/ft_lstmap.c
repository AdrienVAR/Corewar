/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:39:59 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/12 08:53:08 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*frsh;
	t_list	*frsh_start;
	t_list	*flst;

	frsh = NULL;
	if (!lst || !f)
		return (NULL);
	if (!(frsh = ft_lstnew((*f)(lst)->content, (*f)(lst)->content_size)))
		return (NULL);
	frsh_start = frsh;
	while (lst->next)
	{
		lst = lst->next;
		flst = (*f)(lst);
		if (!(frsh->next = ft_lstnew(flst->content, flst->content_size)))
			return (NULL);
		frsh = frsh->next;
	}
	return (frsh_start);
}
