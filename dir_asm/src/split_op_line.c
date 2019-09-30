/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_op_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:18:27 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/30 10:52:50 by gdrai            ###   ########.fr       */
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
		if (env->line[j] == LABEL_CHAR && env->first_w)
		{
			j++;
			break ;
		}
	}
	if (!(env->line_splitted[k] = ft_strnew(j - i + 1)))
		clean_exit(-1, env, "Memory allocation failed\n");
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
			env->first_w = 0;
		}
		else
			i++;
	}
}

void	check_count_op_bis(t_env *env, int i)
{
	if (env->line[i] == ' ' || env->line[i] == '\t')
		env->white_space = 1;
	else if (env->first_w && env->line[i] == SEPARATOR_CHAR)
		clean_exit(i, env, "Error: unexpected SEPARATOR_CHAR\n");
	else if (env->line[i] == SEPARATOR_CHAR)
	{
		env->sep = 1;
		env->count++;
	}
	else if (!env->first_w && env->white_space && env->line[i] != ' '
		&& env->line[i] != '\t' && !env->sep)
		clean_exit(i, env, "Error: expected SEPARATOR_CHAR\n");
	else if (!env->first_w && env->line[i] != ' ' && env->line[i] != '\t')
	{
		env->sep = 0;
		env->white_space = 0;
	}
}

void	check_count_op(t_env *env)
{
	int	i;

	i = 0;
	while (env->line[i] != '\0' && env->line[i] != COMMENT_CHAR)
	{
		if (env->line[i] != ' ' && env->line[i] != '\t'
			&& env->white_space && env->first_w)
		{
			env->count++;
			env->white_space = 0;
			env->first_w--;
		}
		else if (env->line[i] == LABEL_CHAR && env->first_w == 1)
		{
			env->first_w++;
			env->white_space = 1;
		}
		else
			check_count_op_bis(env, i);
		i++;
	}
}

void	split_op_line(t_env *env)
{
	if (env->line == NULL)
		return ;
	env->count = 0;
	env->white_space = 1;
	env->sep = 0;
	env->first_w = 2;
	check_count_op(env);
	if (env->count == 0)
		return ;
	env->first_w = 1;
	if (!(env->line_splitted = (char **)malloc(sizeof(char *)
		* (env->count + 1))))
		clean_exit(-1, env, "Memory allocation failed\n");
	env->line_splitted[env->count] = NULL;
	op_case(env);
}
