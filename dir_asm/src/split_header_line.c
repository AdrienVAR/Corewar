/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_header_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:16:13 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/11 11:32:07 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	**header_case(t_env *env, int count)
{
	char	**tab;
	size_t	i;
	size_t	j;
	int		k;

	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (count + 1))))
		clean_exit(env, "Error: Memory allocation failed\n");
	tab[count] = NULL;
	i = 0;
	k = 0;
	while (k < count)
	{
		if (env->line[i] == '"')
		{
			j = i + 1;
			while (env->line[j] != '"')
				j++;
			j++;
			if (!(tab[k] = ft_memalloc(j - i)))
				clean_exit(env, "Error: Memory allocation failed\n");
			tab[k] = ft_memcpy(tab[k], env->line + i, j - i);
			k++;
			i = j + 1;
		}
		else if (env->line[i] != ' ' && env->line[i] != '\t')
		{
			j = i;
			while (env->line[j] != ' ' && env->line[j] != '\t'
				&& env->line[j] != '"')
				j++;
			if (!(tab[k] = ft_memalloc(j - i + 1)))
				clean_exit(env, "Error: Memory allocation failed\n");
			tab[k] = ft_memcpy(tab[k], env->line + i, j - i);
			k++;
			i = j;
		}
		else
			i++;
	}
	return (tab);
}

int		check_count_header(t_env *env)
{
	int i;
	int count;
	int quote;
	int white_space;

	i = 0;
	count = 0;
	quote = 0;
	white_space = 1;
	while (env->line[i] != '\0' && (env->line[i] != COMMENT_CHAR || quote % 2))
	{
		if (env->line[i] == '"')
		{
			if (env->line[i + 1] == '"')
				count++;
			white_space = 1;
			quote++;
		}
		else if (env->line[i] != ' ' && env->line[i] != '\t' && white_space)
		{
			count++;
			white_space = 0;
		}
		else if ((env->line[i] == ' ' || env->line[i] == '\t') && !(quote % 2))
			white_space = 1;
		i++;
	}
	if (quote != 0 && quote != 2)
		clean_exit(env, "Error: Wrong number of quotes in header\n");
	return (count);
}

char	**split_header_line(t_env *env)
{
	int count;

	if (env->line == NULL)
		return (NULL);
	count = check_count_header(env);
	if (count == 0)
		return (NULL);
	if (count != 2)
		clean_exit(env,
			"Error: Incorrect number of parameters for name or comment\n");
	return (header_case(env, count));
}
