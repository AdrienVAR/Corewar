/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 09:30:52 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"
#include "utils.h"

static void		add_verbose(t_process *process)
{
	t_command command;

	command = process->vm.command;
	ft_printf("P - %5d | op : %s r%d + r%d =>> r%d ( %d + %d = %d)\n",
		process->vm.process_nb,
		command.op.name,
		command.param_conv[0].nb + 1,
		command.param_conv[1].nb + 1,
		command.param_conv[2].nb + 1,
		command.param_ext_conv[0].nb,
		command.param_ext_conv[1].nb,
		command.param_ext_conv[0].nb + command.param_ext_conv[1].nb);
}

void			ex_command_add(t_master *mstr, t_process *process, char *arena)
{
	t_dir_cast	result;
	t_command	command;
	int			reg_dst;

	(void)mstr;
	(void)arena;
	command = process->vm.command;
	reg_dst = command.param_conv[2].nb;
	result.nb = command.param_ext_conv[0].nb + command.param_ext_conv[1].nb;
	memrevcpy(process->registry[reg_dst], result.casted, DIR_SIZE);
	process->carry = !(result.nb) ? YES : NO;
	if (mstr->options.verbose & VERBOSE_OPER)
		add_verbose(process);
}
