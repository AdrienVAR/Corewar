/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_and.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 13:45:34 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"
#include "utils.h"

static void	and_verbose(t_process *process, t_dir_cast *comp)
{
	ft_printf("P - %5d | op : %s %d & %d = %d (=> r%d)\n",
		process->vm.process_nb,
		process->vm.command.op.name,
		comp[0].nb,
		comp[1].nb,
		comp[2].nb,
		process->vm.command.param_conv[2].nb + 1);
}

void		ex_command_and(t_master *mstr, t_process *process, t_arena *arena)
{
	t_dir_cast	comp[3];
	int			reg_dst;
	t_command	command;

	(void)mstr;
	(void)arena;
	command = process->vm.command;
	comp[0] = command.types[0].type != T_DIR ?
	command.param_ext_conv[0] : command.param_conv[0];
	comp[1] = command.types[1].type != T_DIR ?
	command.param_ext_conv[1] : command.param_conv[1];
	reg_dst = command.param_conv[2].nb;
	comp[2].nb = 0;
	comp[2].nb = comp[0].nb & comp[1].nb;
	memrevcpy(process->registry[reg_dst], comp[2].casted, DIR_SIZE);
	process->carry = !(comp[2].nb) ? YES : NO;
	if (mstr->options.verbose & VERBOSE_OPER)
		and_verbose(process, &(comp[0]));
}
