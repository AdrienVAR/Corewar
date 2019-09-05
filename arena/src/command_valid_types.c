/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_valid_types.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:14:14 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/05 12:35:13 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

int			command_valid_types(t_command command)
{
	int		i;
	t_op	op;

	op = command.op;
	i = -1;
	while (++i < op.nb_params)
	{
		if (!(command.types[i].type & op.params_type[i]))
			return (NO);
	}
	while (i < MAX_ARGS_NUMBER)
	{
		if (command.types[i++].type_code)
			return (NO);
	}
	return (YES);
}
