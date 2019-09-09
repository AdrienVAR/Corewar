/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_extract_indirect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesargironvm <cesargironvm@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:52:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/07 18:16:38 by cesargironv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void		command_extract_indirect(t_command *command)
{
	int				i;
	int				p_ind;

	p_ind = -1;
	while (++p_ind < MAX_ARGS_NUMBER)
	{
		if (command->types[p_ind].type != T_IND)
			continue;
		i = 0;
		while (++i <= IND_SIZE)
		{
			command->ind_val[p_ind].casted[IND_SIZE - i] =
				(t_uchar)command->param[p_ind][i - 1];
		}
	}
}
