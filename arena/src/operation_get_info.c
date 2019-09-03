/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_get_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:32:04 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/03 17:14:19 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

t_op		operation_get_info(char op_code)
{
	int i;

	i = -1;
	while (++i < AVAILABLE_OPERATIONS - 1)
	{
		if (g_op_tab[i].id == (unsigned char)op_code)
			return (g_op_tab[i]);
	}
	return (g_op_tab[i]);
}
