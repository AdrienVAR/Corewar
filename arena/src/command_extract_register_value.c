/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_extract_register_value.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:52:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/09 15:40:37 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

t_dir_cast		command_extract_register_value(t_process *process, int reg_n)
{
	t_dir_cast		reg;

	reg.nb = 0;
	if (reg_n < 1 || reg_n > REG_NUMBER)
		return (reg);
	reg_n = reg_n - 1;
	memrevcpy(reg.casted, process->registry[reg_n], DIR_SIZE);
	return (reg);
}
