/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_live.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/14 17:03:10 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void			ex_command_live(t_master *mstr, t_process *process, char *arena)
{
	t_command	command;

	(void)arena;
	command = process->vm.command;
	process->vm.last_live = -1;
	process->vm.alive = command.param_conv[0].nb;
	if (process->vm.alive >= 1
		&& process->vm.alive <= mstr->nb_of_players)
		mstr->last_player_live = process->vm.alive;
	process->vm.alive = 0;
	mstr->live_signal++;
}
