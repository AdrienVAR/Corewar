/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_aff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 09:30:56 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"

static void		aff_verbose(t_process *process)
{
	ft_printf("P - %5d | op : %5s %c\n",
		process->vm.process_nb,
		process->vm.command.op.name,
		process->vm.command.param_ext_conv[0].nb);
}

void			ex_command_aff(t_master *mstr, t_process *process, char *arena)
{
	(void)mstr;
	(void)arena;
	ft_printf("%c\n", process->vm.command.param_ext_conv[0].nb % 256);
	if (mstr->options.verbose & VERBOSE_OPER)
		aff_verbose(process);
}
