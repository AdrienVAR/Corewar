/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_header_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:16:13 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/30 10:47:37 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		fill_name(t_env *env, size_t i, int k)
{
	size_t j;

	j = i;
	while (env->line[j] != ' ' && env->line[j] != '\t'
		&& env->line[j] != '"')
		j++;
	if (!(env->line_splitted[k] = ft_strnew(j - i + 1)))
		clean_exit(-1, env, "Error: Memory allocation failed\n");
	env->line_splitted[k] = ft_memcpy(env->line_splitted[k],
		env->line + i, j - i);
	return (j);
}

int		fill_in_quote(t_env *env, size_t i, int k)
{
	size_t	j;

	j = i + 1;
	while (env->line[j] != '"')
		j++;
	j++;
	if (!(env->line_splitted[k] = ft_strnew(j - i)))
		clean_exit(-1, env, "Error: Memory allocation failed\n");
	env->line_splitted[k] = ft_memcpy(env->line_splitted[k],
		env->line + i, j - i);
	return (j);
}

void	header_case(t_env *env)
{
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	while (k < env->count)
	{
		if (env->line[i] == '"')
		{
			i = fill_in_quote(env, i, k) + 1;
			k++;
		}
		else if (env->line[i] != ' ' && env->line[i] != '\t')
		{
			i = fill_name(env, i, k);
			k++;
		}
		else
			i++;
	}
}

void	check_count_header(t_env *env)
{
	int i;

	i = 0;
	while (env->line[i] != '\0' && (env->line[i] != COMMENT_CHAR
		|| env->quote % 2))
	{
		if (env->line[i] == '"')
		{
			if (env->line[i + 1] == '"')
				env->count++;
			env->white_space = 1;
			env->quote++;
		}
		else if (env->line[i] != ' ' && env->line[i] != '\t'
			&& env->white_space)
		{
			env->count++;
			env->white_space = 0;
		}
		else if ((env->line[i] == ' ' || env->line[i] == '\t')
			&& !(env->quote % 2))
			env->white_space = 1;
		i++;
	}
}

void	split_header_line(t_env *env)
{
	if (env->line == NULL)
		return ;
	env->count = 0;
	env->quote = 0;
	env->white_space = 1;
	check_count_header(env);
	if (env->quote != 0 && env->quote != 2)
		clean_exit(0, env, "Error: Wrong number of quotes in header\n");
	if (env->count == 0)
		return ;
	if (env->count != 2)
		clean_exit(0, env, "Error: Incorrect name or comment\n");
	if (!(env->line_splitted = (char **)ft_memalloc(sizeof(char *)
		* (env->count + 1))))
		clean_exit(-1, env, "Error: Memory allocation failed\n");
	env->line_splitted[env->count] = NULL;
	header_case(env);
}
