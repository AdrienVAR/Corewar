/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:36:10 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/19 15:02:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"

static int		is_integer(char *line)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while ((line[i] >= 8 && line[i] <= 13) || line[i] == 32)
		++i;
	if (line[i] == '+' || line[i] == '-')
		++i;
	while (line[i] == '0')
		++i;
	while (ft_isdigit(line[i + len]))
		len++;
	if ((len && !ft_atoi(line)) || i + len != (int)ft_strlen(line))
		return (NO);
	return (YES);
}

static int		option_check_dump(int argc, char **argv, int *i, t_opt *opt)
{
	if (*i >= argc || ft_strcmp(argv[*i], OPT_DUMP))
		return (NO);
	if (*i + 1 < argc && is_integer(argv[*i + 1]) && ft_atoi(argv[*i + 1]) >= 0)
	{
		opt->end_dump = N_DUMP;
		opt->dump = ft_atoi(argv[*i + 1]);
		(*i)++;
	}
	else
		opt->end_dump = END_DUMP;
	return (YES);
}

static int		option_check_player(char *player, t_opt *option, int i)
{
	char	*end;

	if (!(*player) || !(end = ft_strstr(player, COR_EXT)))
		return (!(*player) ? YES : NO);
	if (ft_strcmp(end, COR_EXT))
		return (NO);
	option->player[option->nb_players][1] = i;
	return (YES);
}

static int		option_check_n(int argc, char **argv, int *i, t_opt *opt)
{
	int player_nb;

	if (*i >= argc || ft_strcmp(argv[*i], OPT_N))
		return (YES);
	if (*i + 2 < argc && is_integer(argv[*i + 1]))
	{
		player_nb = ft_atoi(argv[*i + 1]);
		if (!ft_in_range(player_nb, 1, MAX_PLAYERS))
		{
			ft_putstr("	\e[31mPlayer number not in range (\e[32m >= 1 & <= ");
			ft_putnbr(MAX_PLAYERS);
			ft_putstr("\e[31m)\e[0m\n");
			return (NO);
		}
		if (opt->player[player_nb - 1][0])
		{
			ft_putstr("	\e[31mDual player assignation\n\e[0m");
			return (NO);
		}
		else
			opt->player[player_nb - 1][0] = opt->nb_players + 1;
		*i += 2;
		return (YES);
	}
	ft_putstr("\e[31m	Invalid -n usage\e[0m\n");
	return (NO);
}

static int		option_clean_player(t_opt *opt)
{
	int i;
	int shuttle;
	int p_nb;

	i = -1;
	p_nb = 1;
	shuttle = -1;
	if (!opt->nb_players)
	{
		ft_putstr("	\e[31mNo players given !\e[0m\n");
		return (NO);
	}
	while (++i < MAX_PLAYERS)
	{
		if (opt->player[i][0] && i >= opt->nb_players)
		{
			ft_putstr("	\e[31mInvalid player number assignation\e[0m\n");
			return (NO);
		}
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

int			option_get(t_opt *opt, int argc, char **argv)
{
	int i;

	if (!argc)
		return (NO);
	opt->dump = -1;
	ft_bzero(opt, sizeof(t_opt));
	i = -1;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], OPT_V))
			opt->visu = YES;
		else if (option_check_dump(argc, argv, &i, opt) == YES)
			continue;
		else if (option_check_n(argc, argv, &i, opt) == NO)
			return (NO);
		else if (option_check_player(argv[i], opt, i) == NO)
		{
			ft_putstr("	\e[31mInvalid argument\e[0m\n");
			return (NO);
		}
		else if (++opt->nb_players > MAX_PLAYERS)
			return (NO);
	}
	if (!(option_clean_player(opt)))
		return (NO);
	return (YES);
}
