/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:33:25 by advardon          #+#    #+#             */
/*   Updated: 2019/08/19 17:53:34 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	garbage_collector(t_list **head, void *param)
{
	t_list	*new;

	new = ft_lstnew(NULL, 0);
	new->content = param;
	ft_lstadd(head, new);
}

void	free_gc(t_list *head)
{
	t_list *actual;

	actual = head;
	while (actual)
	{
		free(actual->content);
		actual = actual->next;
	}
	actual = head;
	while (head->next)
	{
		actual = head->next;
		free(head);
		head = actual;
	}
	free(head);
}

/*
void	add_tab_gc(t_list *structure, void **tab)
{
	int i;

	i = 0;
	garbage_collector(&(structure->head_gar_c), tab);
	while (tab[i])
	{
		garbage_collector(&(structure->head_gar_c), tab[i]);
		i++;
	}
}*/
