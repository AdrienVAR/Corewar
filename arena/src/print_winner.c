/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:02:45 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 13:47:48 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/ft_printf.h"

void		print_winner(t_player *player, int someone_lived)
{
	if (someone_lived)
	{
		ft_printf("Player %3.0~%d%~ : %3.0~%s%~ WON\n",
			player->nb, player->name);
		ft_putstr("He was the last alive (that i noticed)\n");
		ft_printf("		%3.0~CONGRATS%~\n");
	}
	else
		ft_putstr("No one looked alive to me : \e[31mNO WINNER\e[0m\n");
}
