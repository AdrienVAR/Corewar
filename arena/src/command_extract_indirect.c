/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_extract_indirect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:52:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/06 12:01:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void		command_extract_indirect(t_command *command)
{
	int				i;
	int				p_ind;

	i = 0;
	p_ind = -1;
	while (++p_ind < MAX_ARGS_NUMBER)
	{
		if (command->types[p_ind].type != T_IND)
			continue;
		while (++i <= IND_SIZE)
		{
			command->ind_val[p_ind].casted[IND_SIZE - i] =
				(t_uchar)command->param[p_ind][i - 1];
		}
	}
}
