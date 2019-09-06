/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_live.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/06 16:17:04 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_live(t_process *process, char *arena)
{
	t_command	command;
	int			i;
	t_int_cast	player;
	int			jump;

	command = process->vm.command;
	jump = command.op.type_needed ? 2 : 1;
	player.nb = 0;
	i = -1;
	while (++i < DIR_SIZE)
		player.casted[DIR_SIZE - 1 - i] =
			arena_val(arena, process->pc + i + jump);
	process->vm.last_live = -1;
	process->vm.alive = player.nb;
}
