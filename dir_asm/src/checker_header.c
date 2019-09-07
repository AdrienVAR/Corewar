/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:01:50 by advardon          #+#    #+#             */
/*   Updated: 2019/09/07 15:40:37 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Name or comment in header must be in double quotes.
*/

void    check_double_quotes(char *str)
{
    int i;

    i = 0;
    if (!str[i] || str[i] != '"')
        clean_exit(NULL, "Missing double quotes in header\n");
    while(str[i])
    {
        i++;
    }
    if (str[i - 1] != '"')
        clean_exit(NULL, "Missing double quotes in header\n");
}

/*
** If format is ok, save champion's name in env.
*/

void    checker_name(char **tab, t_env *env) //check if tab == 2
{
    int i;

    i = 0;
    if (ft_strncmp(tab[i], ".name", 5) == 0)
        i++;
    else
        return;
    //check_double_quotes(tab[i]); to use after modif split_line
    if (ft_strlen(tab[i]) > PROG_NAME_LENGTH)
        clean_exit(NULL, "Champion name too long (Max length 128)\n");
    env->name = tab[i];
}

/*
** If format is ok, save champion's comment in env.
*/

void    checker_comment(char **tab, t_env *env)
{
    int i;

    i = 0;
    if (ft_strncmp(tab[i], ".comment", 8) == 0)
        i++;
    else
        return;
    //check_double_quotes(tab[i]); to use after modif split_line
    if (ft_strlen(tab[i]) > COMMENT_LENGTH)
        clean_exit(NULL, "Champion comment is too long(Max length 2048)\n");
    env->comment = tab[i];
}

/*
** Check if the line has at least two argments. Ret 1 if true.
*/

int check_len_tab(char **tab)
{
    int i;

    i = 0;
    while(tab[i])
        i++;
    if (i < 2)
        return (0);
    return (1);
}

void	create_header(t_env *env, int fd, char *line)
{
	char **tab;

	if (get_next_line(fd, &line) > 0)
	{
		tab = split_line(line, 0);
        if (tab == NULL) //check empty lines
            return ;
        if(!(check_len_tab(tab)))
            return ;
		checker_name(tab, env);
		checker_comment(tab, env);
	}
	else
		clean_exit(NULL, "Champion doesn't have name or comment\n");
}