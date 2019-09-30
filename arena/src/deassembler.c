/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deassembler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:02:21 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/30 16:05:43 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"

void			check_trailing_code(t_master *mstr, t_player *player)
{
	char c;

	if (read(player->fd, &c, 1) > 0)
	{
		ft_printf("%*.0~Player %d => %s%~  Over announced size : %d B\n",
			player->nb + 1, player->nb, player->binary_name, player->code_size);
		exit_program(mstr);
	}
}

static void		check_magic(t_master *mstr, t_player *player)
{
	if (player->magic != COREWAR_EXEC_MAGIC)
	{
		ft_printf("%*.0~Player %d => %s%~  Wrong Magic : Check file \n",
			player->nb + 1, player->nb, player->binary_name, player->code_size);
		exit_program(mstr);
	}
}

void			deassembler(t_master *mstr, t_player *player)
{
	player->magic = binary_read_integer(player, mstr);
	check_magic(mstr, player);
	binary_read_string(
			player, &(player->name[0]), PROG_NAME_LENGTH, mstr);
	binary_read_null(player, mstr);
	player->code_size = binary_read_integer(player, mstr);
	binary_read_string(
			player, &(player->comment[0]), COMMENT_LENGTH, mstr);
	binary_read_null(player, mstr);
	if (player->code_size <= CHAMP_MAX_SIZE && player->code_size > 0)
		binary_read_string(
				player, &(player->exec[0]), player->code_size, mstr);
	else
	{
		ft_printf("%*.0~Player %d => %s%~ size \
too big/null/neg [%d/%2.0~%d%~ B MAX]\n",
			player->nb + 1, player->nb, player->binary_name,
			player->code_size, CHAMP_MAX_SIZE);
		exit_program(mstr);
	}
	check_trailing_code(mstr, player);
}
