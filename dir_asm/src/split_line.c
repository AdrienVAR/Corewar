/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:17:20 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/06 15:19:24 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	**op_case(char *line, int count)
{
	char **tab;
	size_t	i;
	size_t	j;
	int		k;
	int		first_word;
	
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
        clean_exit(NULL, "Memory allocation failed\n");
	tab[count] = NULL;
	i = 0;
	k = 0;
	first_word = 1;
	while (k < count)
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != SEPARATOR_CHAR)
		{
			j = i;
			while (line[j] != ' ' && line[j] != '\t' && line[j] != SEPARATOR_CHAR && line[j] != '\0' && line[j] != COMMENT_CHAR)
			{
				j++;
				if (line[j] == LABEL_CHAR && first_word)
				{
					j++;
					break ;
				}
			}
			if (!(tab[k] = ft_memalloc(j - i + 1)))
        		clean_exit(NULL, "Memory allocation failed\n");
			tab[k] = ft_memcpy(tab[k], line + i, j - i);
			k++;
			first_word = 0;
			i = j;
		}
		else
			i++;
	}
	return(tab);
}

char	**header_case(char *line, int count)
{
	char	**tab;
	size_t	i;
	size_t	j;
	int		k;

	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
        clean_exit(NULL, "Memory allocation failed\n");
	tab[count] = NULL;
	i = 0;
	k = 0;
	while (k < count)
	{
		if (line[i] == '"')
		{
			j = i + 1;
			while (line[j] != '"')
				j++;
			if (!(tab[k] = ft_memalloc(j - i)))
        		clean_exit(NULL, "Memory allocation failed\n");
			tab[k] = ft_memcpy(tab[k], line + i + 1, j - i - 1);
			k++;
			i = j + 1;
		}
		else if (line[i] != ' ' && line[i] != '\t')
		{
			j = i;
			while (line[j] != ' ' && line[j] != '\t' && line[j] != '"')
				j++;
			if (!(tab[k] = ft_memalloc(j - i + 1)))
        		clean_exit(NULL, "Memory allocation failed\n");
			tab[k] = ft_memcpy(tab[k], line + i, j - i);
			k++;
			i = j;
		}
		else
			i++;
	}
	return (tab);
}

int		check_count_header(char *line)
{
	int i;
	int count;
	int quote;
	int white_space;

	i = 0;
	count = 0;
	quote = 0;
	white_space = 1;
	while (line[i] != '\0' && (line[i] != COMMENT_CHAR || quote % 2))
	{
		if (line[i] == '"')
		{
			white_space = 1;
			quote++;
		}
		else if (line[i] != ' ' && line[i] != '\t' && white_space)
		{
			count++;
			white_space = 0;
		}
		else if ((line[i] == ' ' || line[i] == '\t') && !(quote % 2))
			white_space = 1;
		i++;
	}
	if (quote != 0 && quote != 2)
		clean_exit(NULL, "Wrong number of quotes in file\n");
	return (count);
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

char	**split_line(char *line, int option)
{
	int count;

	if (line == NULL)
		return (NULL);
	if (option == 0)
	{
		count = check_count_header(line);
		if (count == 0)
			return (NULL);
		return (header_case(line, count));
	}
	else if (option == 1)
	{
		count = check_count_op(line);
		return (op_case(line, count));
	}
	else
		return (NULL);
}