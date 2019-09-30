/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 18:52:11 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "arena.h"
#include "libft/ft_printf.h"

static void		info_game_start(t_player *player)
{
	ft_printf("%*.0~Player %d%~ (%#x) of size %d Bytes : %3.0~%s%~ [%s]\n",
	player->nb + 1, player->nb, -player->nb, player->code_size,
	player->name, player->comment);
}

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
		info_game_start(player);
		file_closing(player);
	}
}

int				print_usage(void)
{
	ft_putstr("USAGE:./corewar [-a][-visu][-v N][-dump [N]]\
[[-n N] champ.cor]\n\n");
	ft_putstr("********* VISU             ********** \n");
	ft_putstr(" -visu for visualiser\n  (will ignore dump value)\n");
	ft_putstr("********* AFF COMMAND      ********** \n");
	ft_putstr(" -a to activate aff output\n");
	ft_putstr("********* N option         ********** \n");
	ft_putstr(" -n N set following champ to player N\n");
	ft_putstr("********* DUMP option      ********** \n");
	ft_putstr(" -dump [N optional] dump after N cyle\n");
	ft_putstr(" or at the end if no following N\n");
	ft_putstr("*********   VERBOSE        ********** \n");
	ft_putstr(" -v [sum] add them together to compound :\n");
	ft_putstr("   1 for player specific life message\n");
	ft_putstr("   2 for process deaths\n");
	ft_putstr("   4 for process births\n");
	ft_putstr("   8 for process operations\n");
	ft_putstr("   16 for cursor movements\n");
	ft_putstr("   32 for cycles\n");
	return (0);
}

int				main(int argc, char **argv)
{
	t_master	*mstr;
	t_opt		options;

	if (option_get(&options, --argc, ++argv) == NO)
	{
		print_usage();
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
