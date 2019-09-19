/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/19 15:04:30 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "arena.h"

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
	if (mstr->options.end_dump)
		memory_dump(mstr);
	exit_program(mstr);
	return (0);
}
