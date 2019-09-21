/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/21 18:01:21 by cizeur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "arena.h"
#include "libft/ft_printf.h"

static void			print_winner_name(t_player *player)
{
	ft_printf("Player %3.0~%d%~ : %3.0~%s%~ WON\n", player->nb, player->name);
	ft_putstr("He was the last alive (that i noticed)\n");
	ft_printf("		%3.0~CONGRATS%~\n");
}

int				main(int argc, char **argv)
{
	t_master	*mstr;
	t_opt		options;

	if (option_get(&options, --argc, ++argv) == NO)
	{
		ft_putstr(USAGE_STR);
		return (0);
	}
	init(&mstr, &options);
	file_loading(mstr, argv);
	deassembler(mstr);
	file_closing(mstr);
	arena_populate(mstr);
	player_give_process(mstr);
	war(mstr);
	print_winner_name(mstr->players[mstr->last_player_live - 1]);
	if (mstr->options.end_dump)
		memory_dump(mstr);
	free_everything(mstr);
	return (0);
}
