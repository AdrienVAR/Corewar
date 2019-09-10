/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_op_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:18:27 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/10 13:18:53 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "asm.h"

char	**op_case(t_env *env, int count)
{
	char **tab;
	size_t	i;
	size_t	j;
	int		k;
	int		first_word;
	
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
        clean_exit(env, "Memory allocation failed\n");
	tab[count] = NULL;
	i = 0;
	k = 0;
	first_word = 1;
	while (k < count)
	{
		if (env->line[i] != ' ' && env->line[i] != '\t' && env->line[i] != SEPARATOR_CHAR)
		{
			j = i;
			while (env->line[j] != ' ' && env->line[j] != '\t' && env->line[j] != SEPARATOR_CHAR && env->line[j] != '\0' && env->line[j] != COMMENT_CHAR)
			{
				j++;
				if (env->line[j] == LABEL_CHAR && first_word)
				{
					j++;
					break ;
				}
			}
			if (!(tab[k] = ft_memalloc(j - i + 1)))
        		clean_exit(env, "Memory allocation failed\n");
			tab[k] = ft_memcpy(tab[k], env->line + i, j - i);
			k++;
			first_word = 0;
			i = j;
		}
		else
			i++;
	}
	return(tab);
}

int    check_count_op(char *line)
{
    int	i;
	int	count;
	int first_word;
	int white_space;

	i = 0;
	count = 0;
	first_word = 1;
	white_space = 1;
	while (line[i] != '\0' && line[i] != COMMENT_CHAR)
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
		{
			white_space = 1;
			if (count > 0)
				first_word = 0;
		}
		else if (line[i] == LABEL_CHAR && first_word && line[i + 1] != ' '
			&& line[i + 1] != '\t' && line[i + 1] != '\0' && line[i + 1] != COMMENT_CHAR)
			count++;
		else if (line[i] != ' ' && line[i] != '\t' && white_space)
		{
			count++;
			white_space = 0;
		}
		i++;
	}
    return (count);
}

char	**split_op_line(t_env *env)
{
	int count;

	if (env->line == NULL)
		return (NULL);
	count = check_count_op(env->line);
	if (count == 0)
		return (NULL);
	return (op_case(env, count));
}