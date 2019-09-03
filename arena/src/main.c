/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/03 10:57:53 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "arena.h"

int				main(int argc, char **argv)
{
	t_master	*mstr;

	if (!(--argc))
		ft_putstr(USAGE_STR);
	mstr = 0;
	init(&mstr);
	file_loading(mstr, argc, argv);
	deassembler(mstr);
	file_closing(mstr);
	arena_populate(mstr);
	player_give_process(mstr);
	memory_dump(mstr);
	return (0);
}
