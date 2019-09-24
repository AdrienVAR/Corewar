/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:46:42 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/24 09:30:31 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"

static void		sti_verbose(t_process *process, int jump)
{
	t_command	command;
	int			cor;

	command = process->vm.command;
	ft_printf("P - %5d | op : %s ",
		process->vm.process_nb,
		command.op.name);
	ft_printf(" src: r%d (val = %d)",
		command.param_conv[0].nb + 1, command.param_ext_conv[0].nb);
	cor = command.types[1].type == T_REG ? 1 : 0;
	ft_printf(" => dest : pc (val = %d) + ", process->pc);
	if (command.types[1].type != T_DIR)
		ft_printf("%s", command.types[1].type == T_REG ? "r" : "[IND] ");
	ft_printf("%d + ", command.param_conv[1].nb + cor);
	if (command.types[2].type != T_DIR)
		ft_printf("r");
	cor = command.types[2].type == T_REG ? 1 : 0;
	ft_printf("%d", command.param_conv[2].nb + cor);
	ft_printf(" => pc : %d \n", jump);
}

void			ex_command_sti(t_master *mstr, t_process *process, t_arena *arena)
{
	t_command	command;
	t_dir_cast	src;
	t_dir_cast	elem[2];
	int			jump;
	int			i;

	(void)mstr;
	(void)arena;
	command = process->vm.command;
	src = command.param_ext_conv[0];
	elem[0] = command.types[1].type != T_DIR ?
	command.param_ext_conv[1] : command.param_conv[1];
	elem[1] = command.types[2].type != T_DIR ?
	command.param_ext_conv[2] : command.param_conv[2];
	jump = (elem[0].nb + elem[1].nb) % IDX_MOD + process->pc;
	i = -1;
	while (++i < DIR_SIZE)
		arena_val_set(arena, src.casted[DIR_SIZE - 1 - i],
			jump + i, process->vm.player);
	if (mstr->options.verbose & VERBOSE_OPER)
		sti_verbose(process, jump);
}
