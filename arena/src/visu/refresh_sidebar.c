/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_sidebar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:31:57 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 13:41:39 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "utils.h"
#include "arena.h"

static void			cycle_foamy_info(t_master *mstr, t_visu *visu, int start)
{
	char *string;

	string = 0;
	ft_asprintf(&string, "CYCLE : ", mstr->cur_cycle);
	sidebar_text(visu, string, COLOR_BASIC, start);
	ft_asprintf(&string, "Current: %d", mstr->cur_cycle);
	sidebar_text(visu, string, COLOR_LESS_BASIC, -1 - start);
	ft_asprintf(&string, "Actives Processes: %d", mstr->active_processes);
	sidebar_text(visu, string, COLOR_BASIC, -2 - start);
	ft_asprintf(&string, "VIRTUAL FOAMY BAT INFO :");
	sidebar_text(visu, string, COLOR_BASIC, 4 + start);
	ft_asprintf(&string, "Counter to Death : %d",
		mstr->ctd);
	sidebar_text(visu, string, COLOR_LESS_BASIC, -5 - start);
	ft_asprintf(&string, "Foamy bat cycle : %d [Delta : %d]",
		mstr->foamy_bat_cycle, CYCLE_DELTA);
	sidebar_text(visu, string, COLOR_BASIC, -6 - start);
	ft_asprintf(&string, "Checks since reducement : %d / %d",
		mstr->check, MAX_CHECKS);
	sidebar_text(visu, string, COLOR_BASIC, -7 - start);
	ft_asprintf(&string, "Amount of life signals: %d / %d",
		mstr->live_signal, NBR_LIVE);
	sidebar_text(visu, string, COLOR_BASIC, -8 - start);
}

static void			vm_state(t_visu *visu, int start)
{
	char *string;

	string = 0;
	if (visu->update == U_END)
		ft_asprintf(&string, "OVER");
	else if (visu->update != U_REFRESH)
		ft_asprintf(&string, "RUNNING");
	else
		ft_asprintf(&string, "IDLE");
	sidebar_text(visu, string,
		visu->update != U_REFRESH ? 0x00FF00 : COLOR_BASIC, -2 - start);
}

static void			visualiser_info(t_visu *visu, int start)
{
	char *string;

	string = 0;
	ft_asprintf(&string, "VISUALISER INFO :");
	sidebar_text(visu, string, COLOR_BASIC, start);
	ft_asprintf(&string, "Multi turn refresh rate : %d", visu->multi);
	sidebar_text(visu, string, COLOR_LESS_BASIC, -1 - start);
	vm_state(visu, start);
	ft_asprintf(&string, "CONTROLS :");
	sidebar_text(visu, string, COLOR_BASIC, 4 + start);
	ft_asprintf(&string, "[ESC]  : QUIT");
	sidebar_text(visu, string, COLOR_BASIC, -5 - start);
	ft_asprintf(&string, "[SPACE]: One turn");
	sidebar_text(visu, string, COLOR_BASIC, -6 - start);
	ft_asprintf(&string, "[M]    : One multi turn");
	sidebar_text(visu, string, COLOR_BASIC, -7 - start);
	ft_asprintf(&string, "[A]    : Till next event(death or op)");
	sidebar_text(visu, string, COLOR_BASIC, -8 - start);
	ft_asprintf(&string, "[P]    : Till the end");
	sidebar_text(visu, string, COLOR_BASIC, -9 - start);
	ft_asprintf(&string, "[UP]   : Multi ++");
	sidebar_text(visu, string, COLOR_BASIC, -10 - start);
	ft_asprintf(&string, "[DOWN] : Multi --");
	sidebar_text(visu, string, COLOR_BASIC, -11 - start);
}

static void			winner_text(t_master *mstr, t_visu *visu, int start)
{
	char		*string;
	t_player	*player;

	string = 0;
	ft_asprintf(&string, "WINNER IS :", mstr->nb_of_players);
	sidebar_text(visu, string, COLOR_BASIC, start);
	if (!mstr->someone_lived)
	{
		ft_asprintf(&string, "NO WINNERS", mstr->nb_of_players);
		sidebar_text(visu, string, 0x000000, -(start + 6));
		return ;
	}
	else
	{
		player = mstr->players[mstr->last_player_live - 1];
		ft_strlen(player->name) > MAX_VISU_NAME_LEN ?
		ft_asprintf(&string, "Player %d : %*.*s...",
			player->nb, MAX_VISU_NAME_LEN, MAX_VISU_NAME_LEN,
			player->name) :
		ft_asprintf(&string, "Player %d : %*s",
			player->nb, MAX_VISU_NAME_LEN + 3,
			player->name);
		sidebar_text(visu, string, 0x000000, -(start + 6));
	}
}

void				refresh_sidebar(t_master *mstr, t_visu *visu)
{
	cycle_foamy_info(mstr, visu, 0);
	visualiser_info(visu, 10);
	refresh_sidebar_player(mstr, visu);
	if (visu->update == U_END)
		winner_text(mstr, visu, 30);
}
