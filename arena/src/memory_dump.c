/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:26:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/21 19:11:39 by cizeur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"

void			memory_dump(t_master *mstr)
{
	char		*arena;
	char		byte;
	static char hexa[17] = "0123456789abcdef";
	int			i;

	arena = mstr->arena;
	i = -1;
	ft_printf("0x0000 : ", 0);
	while (++i < MEM_SIZE)
	{
		byte = arena_val_get(arena, i);
		if (i && !(i % DUMP_SIZE))
			ft_printf("\n%#.4x : ", i);
		ft_putchar(hexa[(t_uchar)byte / 16]);
		ft_putchar(hexa[(t_uchar)byte % 16]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
