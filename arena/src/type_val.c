/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:38:16 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/06 14:41:57 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

t_type		type_val(int type_code)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if (g_type[i].type_code == type_code)
			break ;
	}
	return (g_type[i]);
}
