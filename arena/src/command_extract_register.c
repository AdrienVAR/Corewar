/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_extract_register.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:52:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/06 11:33:23 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

int			command_extract_register(t_command *command)
{
	int				i;
	int				p_ind;
	int				reg;

	i = 0;
	p_ind = -1;
	while (++p_ind < MAX_ARGS_NUMBER)
	{
		if (command->types[p_ind].type != T_REG)
			continue;
		while (++i <= REG_SIZE)
		{
			command->reg_val[p_ind].casted[REG_SIZE - i] =
				(t_uchar)command->param[p_ind][i - 1];
			reg = command->reg_val[p_ind].nb;
		}
		if (!(reg >= 1 && reg <= REG_NUMBER))
			return (NO);
	}
	return (YES);
}
