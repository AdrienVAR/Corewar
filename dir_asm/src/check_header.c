/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:14:17 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/30 13:52:09 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft/get_next_line.h"

/*
** Name or comment in header must be in double quotes.
*/

void	check_double_quotes(t_env *env)
{
	int i;

	i = 0;
	while (env->line_splitted[1][i])
		i++;
	if (env->line_splitted[1][0] != '"' || env->line_splitted[1][i - 1] != '"')
		clean_exit(-1, env, "Missing double quotes in header\n");
}

/*
** If format is ok, save champion's name in env.
*/

int		checker_name(t_env *env)
{
	if (ft_strcmp(env->line_splitted[0], NAME_CMD_STRING) != 0)
		return (0);
	check_double_quotes(env);
	if (ft_strlen(env->line_splitted[1]) - 2 > PROG_NAME_LENGTH)
		clean_exit(-1, env, "Champion name too long (Max length 128)\n");
	if (env->name)
		clean_exit(-1, env, "too many champion's .name\n");
	env->name = ft_strndup(env->line_splitted[1] + 1,
		ft_strlen(env->line_splitted[1]) - 2);
	return (1);
}

/*
** If format is ok, save champion's comment in env.
*/

int		checker_comment(t_env *env)
{
	if (ft_strcmp(env->line_splitted[0], COMMENT_CMD_STRING) != 0)
		return (0);
	check_double_quotes(env);
	if (ft_strlen(env->line_splitted[1]) - 2 > COMMENT_LENGTH)
		clean_exit(-1, env, "Champion comment is too long(Max length 2048)\n");
	if (env->comment)
		clean_exit(-1, env, "too many champion's .comment\n");
	env->comment = ft_strndup(env->line_splitted[1] + 1,
		ft_strlen(env->line_splitted[1]) - 2);
	return (1);
}

void	check_header(t_env *env)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (get_next_line(env->fd, &env->line) > 0)
		{
			env->num_line++;
			split_header_line(env);
			if (env->line_splitted != NULL)
			{
				if (!checker_name(env) && !checker_comment(env))
					clean_exit(-1, env, "Invalid comment or name\n");
				else
					i++;
			}
			clean_line_readed(env);
		}
		else
			clean_exit(-1, env, "Error : end of file\n");
	}
}
