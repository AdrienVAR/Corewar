/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command_aff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 13:45:26 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"

static void	aff_verbose(t_process *process)
{
	ft_printf("P - %5d | op : %5s %c\n",
		process->vm.process_nb,
		process->vm.command.op.name,
		process->vm.command.param_ext_conv[0].nb);
}

static void	update_aff_buffer(t_master *mstr, t_process *process)
{
	t_player	*player;
	int			ind;
	int			i;
	char		c;

	c = process->vm.command.param_ext_conv[0].nb % 256;
	if (!c)
		return ;
	player = mstr->players[process->vm.player - 1];
	ind = player->buffer_aff_pos;
	if (ind < BUFFER_AFF_SIZE)
	{
		player->buffer_aff[ind] = c;
		player->buffer_aff_pos++;
	}
	else
	{
		i = 0;
		while (++i < BUFFER_AFF_SIZE)
			player->buffer_aff[i - 1] = player->buffer_aff[i];
		player->buffer_aff[ind - 1] = c;
	}
}

void		ex_command_aff(t_master *mstr, t_process *process, t_arena *arena)
{
	t_player	*player;

	(void)arena;
	update_aff_buffer(mstr, process);
	player = mstr->players[process->vm.player - 1];
	if (mstr->options.aff == YES)
		ft_printf("%*.~%s[%d]%~ said :\n[%s]\n",
		player->nb + 1, player->name, player->nb,
		player->buffer_aff);
	if (mstr->options.verbose & VERBOSE_OPER)
		aff_verbose(process);
}
