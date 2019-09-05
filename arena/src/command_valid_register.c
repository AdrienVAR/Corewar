/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_valid_register.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:52:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/05 16:02:42 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

int			command_valid_register(t_command command, int param_ind)
{
	int				i;
	t_reg_cast		reg;
	t_uchar			test;

	i = 0;
	while (++i <= REG_SIZE)
	{
		test = (t_uchar)command.param[param_ind][i - 1];
		reg.casted[REG_SIZE - i] = (t_uchar)command.param[param_ind][i - 1];
	}
	if (reg.nb >= 1 && reg.nb <= REG_NUMBER)
		return (reg.nb);
	return (NO);
}
