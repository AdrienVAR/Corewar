/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/11 17:10:05 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"

void			ex_command_fork(t_master *mstr, t_process *process, char *arena)
{
	int			i;
	int			jump;
	t_ind_cast	fork_jump;
	t_process	*new_process;

	jump = process->vm.command.op.type_needed ? 2 : 1;
	i = -1;
	while (++i < IND_SIZE)
		fork_jump.casted[IND_SIZE - 1 - i] =
			arena_val(arena, process->pc + i + jump);
	if (!(new_process = (t_process *)ft_memalloc(sizeof(t_process))))
		exit_program(mstr);
	new_process->carry = process->carry;
	new_process->pc = process->pc + fork_jump.nb % IDX_MOD;
	ft_memcpy(new_process->registry, process->registry, sizeof(process->registry));
	new_process->next = mstr->process;
	new_process->vm.process_nb = ++mstr->running_processes;
	mstr->process = new_process;
	printf("processes born %d\n", mstr->running_processes);
}
