/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:49:42 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/22 16:36:17 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strtabdel(char ***tab, int tofree)
{
	if (!tab || !*tab)
		return ;
	if (tofree)
	{
		while (**tab)
			free(**tab);
		free(*tab);
		*tab = NULL;
	}
	else
		*tab = NULL;
}
