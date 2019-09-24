/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_lld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 09:32:59 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"
#include "utils.h"

static void		lld_verbose(t_process *process, int load_val)
{
	t_command command;

	command = process->vm.command;
	if (command.types[0].type == T_IND)
		ft_printf("P - %5d | op : %s [IND %d = %d] =>  r%d\n",
		process->vm.process_nb,
		command.op.name,
		command.param_conv[0].nb,
		load_val,
		command.param_conv[1].nb + 1);
	else
		ft_printf("P - %5d | op : %s %d =>  r%d\n",
		process->vm.process_nb,
		command.op.name,
		command.param_conv[0].nb,
		command.param_conv[1].nb + 1);
}

void			ex_command_lld(t_master *mstr, t_process *process, t_arena *arena)
{
	t_command	command;
	t_dir_cast	load_val;
	t_ind_cast	ind_case;
	int			i;

	(void)mstr;
	(void)arena;
	command = process->vm.command;
	i = -1;
	while (command.types[0].type == T_IND && ++i < IND_SIZE)
		ind_case.casted[i] =
			(command.param_ext_conv[0].casted[DIR_SIZE - IND_SIZE + i]);
	load_val.nb = command.types[0].type == T_IND ?
		ind_case.nb : command.param_conv[0].nb;
	memrevcpy(process->registry[command.param_conv[1].nb],
		load_val.casted, DIR_SIZE);
	process->carry = !load_val.nb ? YES : NO;
	if (mstr->options.verbose & VERBOSE_OPER)
		lld_verbose(process, load_val.nb);
}
