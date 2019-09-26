/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_op_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:18:27 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/26 11:31:22 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		fill_op(t_env *env, size_t i, int k)
{
	size_t j;

	j = i;
	while (env->line[j] != ' ' && env->line[j] != '\t' && env->line[j]
		!= SEPARATOR_CHAR && env->line[j] != '\0'
			&& env->line[j] != COMMENT_CHAR)
	{
		j++;
		if (env->line[j] == LABEL_CHAR && env->first_word)
		{
			j++;
			break ;
		}
	}
	if (!(env->line_splitted[k] = ft_strnew(j - i + 1)))
		clean_exit(env, "Memory allocation failed\n");
	env->line_splitted[k] = ft_memcpy(env->line_splitted[k],
		env->line + i, j - i);
	return (j);
}

void	op_case(t_env *env)
{
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	while (k < env->count)
	{
		if (env->line[i] != ' ' && env->line[i] != '\t'
			&& env->line[i] != SEPARATOR_CHAR)
		{
			i = fill_op(env, i, k);
			k++;
			env->first_word = 0;
		}
		else
			i++;
	}
}

void	check_count_op(t_env *env)
{
	int	i;

	i = 0;
	while (env->line[i] != '\0' && env->line[i] != COMMENT_CHAR)
	{
		if (env->line[i] == ' ' || env->line[i] == '\t'
			|| env->line[i] == SEPARATOR_CHAR)
		{
			env->white_space = 1;
			if (env->count > 0)
				env->first_word = 0;
		}
		else if (env->line[i] == LABEL_CHAR && env->first_word &&
			env->line[i + 1] != ' ' && env->line[i + 1] != '\t' &&
				env->line[i + 1] != '\0' && env->line[i + 1] != COMMENT_CHAR)
			env->count++;
		else if (env->line[i] != ' ' && env->line[i] != '\t'
			&& env->white_space)
		{
			env->count++;
			env->white_space = 0;
		}
		i++;
	}
}

void	split_op_line(t_env *env)
{
	if (env->line == NULL)
		return ;
	env->count = 0;
	env->white_space = 1;
	env->first_word = 1;
	check_count_op(env);
	if (env->count == 0)
		return ;
	env->first_word = 1;
	if (!(env->line_splitted = (char **)malloc(sizeof(char *)
		* (env->count + 1))))
		clean_exit(env, "Memory allocation failed\n");
	env->line_splitted[env->count] = NULL;
	op_case(env);
}
