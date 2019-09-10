/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_zjmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/10 09:35:45 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_zjmp(t_process *process, char *arena)
{
	int			i;
	int			jump;
	t_ind_cast	zjmp;

	if (process->carry == NO)
		return ;
	jump = process->vm.command.op.type_needed ? 2 : 1;
	i = -1;
	while (++i < IND_SIZE)
		zjmp.casted[IND_SIZE - 1 - i] =
			arena_val(arena, process->pc + i + jump);
	process->pc = process->pc + zjmp.nb % IDX_MOD;
}
