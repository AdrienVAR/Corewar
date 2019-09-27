/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_sidebar_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:31:57 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 14:19:56 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "utils.h"
#include "arena.h"

static void		player_info(t_master *mstr, t_visu *visu, int start)
{
	char		*string;
	t_player	*player;
	int			color;
	int			i;

	string = 0;
	ft_asprintf(&string, "PLAYER INFO : %d players", mstr->nb_of_players);
	sidebar_text(visu, string, COLOR_BASIC, start++);
	ft_asprintf(&string, "player n :            name [lives]");
	sidebar_text(visu, string, color_dimmer(COLOR_BASIC, 50), -start++);
	i = -1;
	while (++i < mstr->nb_of_players)
	{
		player = mstr->sorted_player[i];
		color = player_color(player->nb);
		ft_strlen(player->name) > MAX_VISU_NAME_LEN ?
		ft_asprintf(&string, "Player %d : %*.*s... [%d]",
			player->nb, MAX_VISU_NAME_LEN, MAX_VISU_NAME_LEN,
			player->name, player->life_signals) :
		ft_asprintf(&string, "Player %d : %*s [%d]",
			player->nb, MAX_VISU_NAME_LEN + 3,
			player->name, player->life_signals);
		sidebar_text(visu, string, color, -(i + start));
	}
}

static void		player_aff(t_master *mstr, t_visu *visu, int start)
{
	char		*string;
	t_player	*player;
	int			color;
	int			i;

	string = 0;
	ft_asprintf(&string, "PLAYER AFF : %d players", mstr->nb_of_players);
	sidebar_text(visu, string, COLOR_BASIC, start++);
	i = -1;
	while (++i < mstr->nb_of_players)
	{
		player = mstr->players[i];
		color = player_color(player->nb);
		ft_strlen(player->name) > MAX_VISU_NAME_LEN ?
		ft_asprintf(&string, "Player %d : %*.*s...",
			player->nb, MAX_VISU_NAME_LEN + 4, MAX_VISU_NAME_LEN,
			player->name) :
		ft_asprintf(&string, "Player %d : %*s",
			player->nb, MAX_VISU_NAME_LEN + 7,
			player->name);
		sidebar_text(visu, string, color, -(2 * i + start));
		ft_asprintf(&string, "[%s]", player->buffer_aff);
		sidebar_text(visu, string, color, -(2 * i + 1 + start));
	}
}

void			refresh_sidebar_player(t_master *mstr, t_visu *visu)
{
	player_info(mstr, visu, 23);
	if (visu->update != U_END)
		player_aff(mstr, visu, 30);
}
