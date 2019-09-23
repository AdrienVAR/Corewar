/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:36:10 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 10:21:22 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "utils.h"

static int		option_dump_verbose(int argc, char **argv, int *i, t_opt *opt)
{
	int which;

	if (*i >= argc || (ft_strcmp(argv[*i], OPT_DUMP)
		&& ft_strcmp(argv[*i], OPT_VERB)))
		return (NO);
	which = !ft_strcmp(argv[*i], OPT_DUMP) ? 1 : 0;
	if (*i + 1 < argc && is_integer(argv[*i + 1]) && ft_atoi(argv[*i + 1]) >= 0)
	{
		opt->end_dump = which ? N_DUMP : opt->end_dump;
		opt->dump = which ? ft_atoi(argv[*i + 1]) : opt->dump;
		opt->verbose = !which ? ft_atoi(argv[*i + 1]) : opt->verbose;
		(*i)++;
	}
	else
	{
		opt->verbose = !which ? 0 : opt->verbose;
		opt->end_dump = which ? END_DUMP : opt->end_dump;
	}
	return (YES);
}

static int		option_check_player(char *player, t_opt *option, int i)
{
	char	*end;

	if (!(player))
		return (YES);
	if (!(end = ft_strstr(player, COR_EXT)) || ft_strcmp(end, COR_EXT))
	{
		ft_printf("	Arg : %2.0~%s%~ not ending in .cor\
: %2.0~check validity%~\n", player);
		return (NO);
	}
	option->player[option->nb_players][1] = i;
	if (++option->nb_players <= MAX_PLAYERS)
		return (YES);
	ft_printf("Too much players stay under %3.0~%d%~\n", MAX_PLAYERS);
	return (NO);
}

static int		option_check_n(int argc, char **argv, int *i, t_opt *opt)
{
	int player_nb;

	if (ft_strcmp(argv[*i], OPT_N))
		return (YES);
	if (*i + 2 < argc && is_integer(argv[*i + 1]))
	{
		player_nb = ft_atoi(argv[*i + 1]);
		if (!ft_in_range(player_nb, 1, MAX_PLAYERS))
			ft_printf("	Player nb %2.0~%d%~ out of range\
(between %3.0~1%~ and %3.0~%d%~)\n", player_nb, MAX_PLAYERS);
		else if (opt->player[player_nb - 1][0])
			ft_printf("Player nb : %2.0~%d%~ already assigned\n", player_nb);
		else
		{
			opt->player[player_nb - 1][0] = opt->nb_players + 1;
			*i += 2;
			return (YES);
		}
	}
	ft_printf("	Invalid -n usage : %3.0~-n [nb] [player.cor]%~\n");
	return (NO);
}

static int		option_set_player(t_opt *opt)
{
	int i;
	int shuttle;
	int p_nb;

	i = -1;
	p_nb = 1;
	shuttle = -1;
	while (++i < MAX_PLAYERS)
	{
		if (opt->player[i][0] && i >= opt->nb_players)
			return (NO);
		else if (opt->player[i][0] == p_nb && (i = -1))
			p_nb++;
		else if (!opt->player[i][0] && i < opt->nb_players && shuttle == -1)
			shuttle = i;
		if (i == MAX_PLAYERS - 1 && shuttle == -1)
			break ;
		if (i == MAX_PLAYERS - 1 && (opt->player[shuttle][0] = p_nb++))
		{
			i = -1;
			shuttle = -1;
		}
	}
	return (YES);
}

int				option_get(t_opt *opt, int argc, char **argv)
{
	int i;

	if (!argc)
		return (NO);
	opt->dump = -1;
	ft_bzero(opt, sizeof(t_opt));
	i = -1;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], OPT_VISU))
			opt->visu = YES;
		else if (option_dump_verbose(argc, argv, &i, opt) == YES)
			continue;
		else if (option_check_n(argc, argv, &i, opt) == NO)
			return (NO);
		else if (option_check_player(argv[i], opt, i) == NO)
			return (NO);
	}
	if (opt->nb_players && (option_set_player(opt)))
		return (YES);
	!opt->nb_players ?
	ft_putstr("	\e[31mNO PLAYERS GIVEN !\e[0m\n") :
	ft_putstr("	\e[31mNumber assignation to high\e[0m\n");
	return (NO);
}
