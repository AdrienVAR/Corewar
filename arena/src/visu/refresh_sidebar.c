/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_sidebar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:31:57 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 12:08:21 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "utils.h"
#include "arena.h"
#include <mlx.h>

void		write_side_bar_text(t_visu *visu, char *line, int color, int line_nb)
{
	if (line_nb >= 0)
		mlx_string_put(visu->mem_ptr[MLX_PTR], visu->mem_ptr[WIN_PTR],
				RIGHT_BAR_X + STD_BUF, TOP_Y + line_nb * STD_NEW_LINE,
				color, line);
	else
		mlx_string_put(visu->mem_ptr[MLX_PTR], visu->mem_ptr[WIN_PTR],
				RIGHT_BAR_X + 2 * STD_BUF, TOP_Y - line_nb * STD_NEW_LINE,
				color_dimmer(color, 80), line);
	ft_memdel((void **)&line);
}

static void		cycle_foamy_info(t_master *mstr, t_visu *visu)
{
	char *string;

	string = 0;
	ft_asprintf(&string, "CYCLE : ", mstr->cur_cycle);
	write_side_bar_text(visu, string, COLOR_BASIC, 0);
	ft_asprintf(&string, "Current: %d", mstr->cur_cycle);
	write_side_bar_text(visu, string, COLOR_LESS_BASIC, -1);
	ft_asprintf(&string, "Actives Processes: %d", mstr->active_processes);
	write_side_bar_text(visu, string, COLOR_BASIC, -2);
	ft_asprintf(&string, "VIRTUAL FOAMY BAT INFO :");
	write_side_bar_text(visu, string, COLOR_BASIC, 4);
	ft_asprintf(&string, "Counter to Death : %d",
		mstr->ctd);
	write_side_bar_text(visu, string, COLOR_LESS_BASIC, -5);
	ft_asprintf(&string, "Foamy bat cycle : %d [Delta : %d]",
		mstr->foamy_bat_cycle, CYCLE_DELTA);
	write_side_bar_text(visu, string, COLOR_BASIC, -6);
	ft_asprintf(&string, "Checks since reducement : %d / %d",
		mstr->check, MAX_CHECKS);
	write_side_bar_text(visu, string, COLOR_BASIC, -7);
	ft_asprintf(&string, "Amount of life signals: %d / %d",
		mstr->live_signal, NBR_LIVE);
	write_side_bar_text(visu, string, COLOR_BASIC, -8);
}

static void		visualiser_info(t_visu *visu)
{
	char *string;

	string = 0;
	ft_asprintf(&string, "VISUALISER INFO :");
	write_side_bar_text(visu, string, COLOR_BASIC, 10);
	ft_asprintf(&string, "Multi turn refresh rate : %d", visu->multi);
	write_side_bar_text(visu, string, COLOR_LESS_BASIC, -11);
	if (visu->update != U_REFRESH)
		ft_asprintf(&string, "RUNNING");
	else
		ft_asprintf(&string, "IDLE");
	write_side_bar_text(visu, string,
		visu->update != U_REFRESH ? 0x00FF00 : COLOR_BASIC, -12);
	ft_asprintf(&string, "CONTROLS :");
	write_side_bar_text(visu, string, COLOR_BASIC, 14);
	ft_asprintf(&string, "[ESC] : QUIT");
	write_side_bar_text(visu, string, COLOR_BASIC, -15);
	ft_asprintf(&string, "[SPACE] : One turn");
	write_side_bar_text(visu, string, COLOR_BASIC, -16);
	ft_asprintf(&string, "[M] : One multi turn");
	write_side_bar_text(visu, string, COLOR_BASIC, -17);
	ft_asprintf(&string, "[A] : Till next event");
	write_side_bar_text(visu, string, COLOR_BASIC, -18);
	ft_asprintf(&string, "[P] : Till the end");
	write_side_bar_text(visu, string, COLOR_BASIC, -19);
}

static void		player_info(t_master *mstr, t_visu *visu)
{
	char		*string;
	t_player	*player;
	int			color;
	int			i;

	string = 0;
	ft_asprintf(&string, "PLAYER INFO : %d players", mstr->nb_of_players);
	write_side_bar_text(visu, string, COLOR_BASIC, 21);
	i = -1;
	while (++i < mstr->nb_of_players)
	{
		player = mstr->players[i];
		color = player_color(player->nb);
		ft_strlen(player->name) > MAX_VISU_NAME_LEN ?
		ft_asprintf(&string, "Player %d : %*.*s... : %d",
			i + 1, MAX_VISU_NAME_LEN ,MAX_VISU_NAME_LEN,
			player->name, player->life_signals) :
		ft_asprintf(&string, "Player %d : %*s : %d",
			i + 1, MAX_VISU_NAME_LEN + 3 ,player->name, player->life_signals);
		write_side_bar_text(visu, string, color, -(22 + i));
	}



}

void		refresh_sidebar(t_master *mstr, t_visu *visu)
{
	cycle_foamy_info(mstr, visu);
	visualiser_info(visu);
	player_info(mstr, visu);
}