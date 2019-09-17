/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_lldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/17 18:22:45 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

static void			lldi_verbose(t_process *process, int jump, int dest_val)
{
	t_command	command;
	int			cor;

	command = process->vm.command;
	printf("P - %5d | op : %s ",
		process->vm.process_nb,
		command.op.name);
	cor = command.types[0].type == T_REG ? 1 : 0;
	if (command.types[0].type != T_DIR)
		printf("%s", command.types[0].type == T_REG ? "r" : "[IND] ");
	printf("%d + ", command.param_conv[0].nb + cor);
	cor = command.types[1].type == T_REG ? 1 : 0;
	if (command.types[1].type == T_REG)
		printf("r");
	printf("%d = > r%d", command.param_conv[1].nb + cor,
		command.param_conv[2].nb + 1);
	printf(" from pc : %d (val = %d)\n", jump, dest_val);
}

void			ex_command_lldi(t_master *mstr, t_process *process, char *arena)
{
	t_command	command;
	t_dir_cast	elem[3];
	t_dir_cast	dest_val;
	int			jump;
	int			i;

	(void)mstr;
	command = process->vm.command;
	elem[0] = command.types[0].type != T_DIR ?
	command.param_ext_conv[0] : command.param_conv[0];
	elem[1] = command.types[1].type != T_DIR ?
	command.param_ext_conv[1] : command.param_conv[1];
	elem[2] = command.param_conv[2];
	jump = (elem[0].nb + elem[1].nb) + process->pc;
	i = -1;
	while (++i < DIR_SIZE)
		dest_val.casted[DIR_SIZE - i - 1] =
			arena_val_get(arena, jump + i);
	lldi_verbose(process, jump, dest_val.nb);
	memrevcpy(process->registry[elem[2].nb], dest_val.casted, DIR_SIZE);
	process->carry = !dest_val.nb ? YES : NO;
}
