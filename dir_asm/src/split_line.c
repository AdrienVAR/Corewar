/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:17:20 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/04 15:57:06 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "<stdio.h>
#include <stdlib.h>
#define COMMENT_CHAR '#'
#define SEPARATOR_CHAR ','
#define LABEL_CHAR	':'"

/*
** split_line 
** 2 parameters : the line to analyse
**                the option (0 if header, 1 if operation)
**
** return NULL : option not 0 or 1
**               number of quotemark different from 0 or 2 in option 0
**				 1 or 0 strings to return
**
** return a char** if evrything is OK
*/

int     count_tab(char *line)
{
    int i;
    int j;
    int count;
    int k;

    i = 0;
    j = 0;
    k = 1;
    count = 0;
    while (line[i] != '\0' && line[i] != COMMENT_CHAR)
    {
        if (line[i] == '"')
		{
			k = 1;
			j++;
			if (j == 1)
				count++;
		}
        else if ((line[i] == ' ' || line[i] == '\t') && j != 1)
            k = 1;
        else if (line[i] != ' ' && line[i] != '\t' && j != 1)
        {
            if (k == 1)
            {
                k = 0;
                count++;
            }
        }
        i++;
    }
    return (count);
}

int     check_quotemark(char *line)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (line[i] != '\0' && line[i] != COMMENT_CHAR)
    {
        if (line[i] == '"')
            count++;
        i++;
    }
    return (count);
}

char    *prepare_op_line(char *line)
{
    int	i;

    i = 0;
    while (line[i] != '\0' && line[i] != COMMENT_CHAR)
    {
        if (line[i] == SEPARATOR_CHAR)
            line[i] = ' ';
        i++;
    }
	i = 0;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t')
	{
		if (line[i] == LABEL_CHAR)
			line[i] = ' ';
		i++;
	}
    return (line);
}

char	**fill_tab(char *line, char **tab)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != COMMENT_CHAR)
	{
		while (line[i] != '\0' && line[i] != COMMENT_CHAR && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] != '\0' && line[i] != COMMENT_CHAR)
		{
			if (line[i] == '"')
			{
				i++;
				k = i;
				while (line[k] != '"')
					k++;
				k -= i;
				if (!(tab[j] = (char *)malloc(sizeof(char) * (k + 1))))
					return (NULL);
				l = 0;
				while (l < k)
					tab[j][l++] = line[i++];
				tab[j++][l] = '\0';
				i++;
			}
			else
			{
				k = i;
				while (line[k] != '\0' && line[k] != COMMENT_CHAR && line[k] != '"' && line[k] != ' ' && line[k] != '\t')
					k++;
				k -= i;
				if (!(tab[j] = (char *)malloc(sizeof(char) * (k + 1))))
					return (NULL);
				l = 0;
				while (l < k)
					tab[j][l++] = line[i++];
				tab[j++][l] = '\0';
			}
		}
	}
	return (tab);
}

char    **split_line(char *line, int option)
{
    char    **tab;
    int     count;

    if (option == 0)
    {
        count = check_quotemark(line);
            if (count != 0 && count != 2)
                return (NULL);
    }
    else if (option == 1)
        line = prepare_op_line(line);
	else
		return (NULL);
    count = count_tab(line);
	if (count <= 1)
		return (NULL);
    if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
        return (NULL);
    tab[count] = NULL;
	tab = fill_tab(line, tab);
	if (!tab)
		return (NULL);
    return(tab);
}

int     main(int argc, char **argv)
{
    char **tab;
	int i = 0;

    (void)argc;
    tab = split_line(argv[1], atoi(argv[2]));
	if (tab)
	{
		while (tab[i])
			printf("%s\n", tab[i++]);
	}
}