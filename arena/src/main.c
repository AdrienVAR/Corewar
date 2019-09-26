/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/26 21:28:33 by cizeur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "arena.h"
#include "libft/ft_printf.h"

static void		load_champions(t_master *mstr, char **argv)
{
	int			i;
	int			player_nb;
	t_player	*player;

	i = -1;
	while (++i < mstr->nb_of_players)
	{

		player_nb =
		mstr->options.player[mstr->options.player[i][0] - 1][1];
		player = mstr->players[i];
		file_loading(mstr, player, argv[player_nb]);
		player->nb = i + 1;
		deassembler(mstr, player);
		file_closing(player);
	}
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
	load_champions(mstr, argv);
	arena_populate(mstr);
	player_give_process(mstr);
	mstr->options.visu == YES ? visu_corewar(mstr) : war(mstr);
	if (mstr->options.end_dump != N_DUMP)
		print_winner(mstr->players[mstr->last_player_live - 1],
			mstr->someone_lived);
	if (mstr->options.end_dump)
		memory_dump(mstr);
	free_everything(mstr);
	return (0);
}
