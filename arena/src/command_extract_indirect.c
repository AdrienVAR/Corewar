/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_extract_indirect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:52:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/09 16:07:11 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void		command_extract_indirect(t_command *command)
{
	int				p_ind;

	p_ind = -1;
	while (++p_ind < MAX_ARGS_NUMBER)
	{
		command->ind_val[p_ind].nb = 0;
		if (command->types[p_ind].type != T_IND)
			continue;
		memrevcpy(command->ind_val[p_ind].casted,
		command->param[p_ind], IND_SIZE);
	}
}
