/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:26:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/14 09:43:00 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"

void			memory_dump(t_master *mstr)
{
	char		*arena;
	char		byte;
	static char hexa[17] = "0123456789abcdef";
	int			i;

	arena = mstr->arena;
	i = -1;
	while (++i < MEM_SIZE)
	{
		byte = arena_val_get(arena, i);
		if (i && !(i % DUMP_SIZE))
			ft_putchar('\n');
		ft_putchar(hexa[(t_uchar)byte / 16]);
		ft_putchar(hexa[(t_uchar)byte % 16]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
