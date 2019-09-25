/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 12:27:17 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "arena.h"
#include "libft/ft_printf.h"

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
	mstr->options.visu == YES ? visu_corewar(mstr) : war(mstr);
	if (mstr->options.end_dump != N_DUMP)
		print_winner(mstr->players[mstr->last_player_live - 1],
			mstr->someone_lived);
	if (mstr->options.end_dump)
		memory_dump(mstr);
	free_everything(mstr);
	return (0);
}
