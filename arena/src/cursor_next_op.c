/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_next_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:41:18 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 09:40:36 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"

static	void	cursor_verbose(int old_pc, int new_pc, int pcs_nb, int verb)
{
	if (!(verb & VERBOSE_CURS))
		return ;
	ft_printf("Cursor    : %#06x -> %#06x = %d (P - %5d)\n",
		old_pc, new_pc, new_pc - old_pc, pcs_nb);
}

void			cursor_next_op(t_process *process, int verbose)
{
	int			i;
	int			pc;
	t_command	command;
	int			size;

	command = process->vm.command;
	process->pc = process->pc % MEM_SIZE;
	process->pc += process->pc < 0 ? MEM_SIZE : 0;
	pc = process->pc;
	if (command.op.id == 9 && process->carry)
		return ;
	pc += !command.op.type_needed ? 1 + command.op.dir_size : 2;
	if ((i = -1) && command.op.type_needed)
	{
		while (++i < command.op.nb_params)
		{
			size = command.types[i].size;
			size = command.types[i].type == T_DIR ?
				command.op.dir_size : size;
			pc += size;
		}
	}
	cursor_verbose(process->pc, pc % MEM_SIZE,
	process->vm.process_nb, verbose);
	process->pc = pc % MEM_SIZE;
}
