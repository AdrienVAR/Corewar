/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:26:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/02 15:51:51 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"

void			memory_dump(t_master *mstr)
{
	char *arena;
	static char hexa[17] = "0123456789abcdef";
	int i;

	arena = mstr->arena;
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i && !(i % DUMP_SIZE))
			ft_putchar('\n');
		ft_putchar(hexa[((unsigned char)arena[i] / 16)]);
		ft_putchar(hexa[((unsigned char)arena[i] % 16)]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
