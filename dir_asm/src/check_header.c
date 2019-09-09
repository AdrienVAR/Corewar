/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:14:17 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/09 16:58:18 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Name or comment in header must be in double quotes.
*/
void    check_double_quotes(t_env *env)
{
    int i;

    i = 0;
    while (env->line_splitted[1][i])
		i++;
	if (env->line_splitted[1][0] != '"' || env->line_splitted[1][i - 1] != '"')
        clean_exit(env, "Missing double quotes in header\n");
}

/*
** If format is ok, save champion's name in env.
*/
int    checker_name(t_env *env)
{
    if (ft_strncmp(env->line_splitted[0], ".name", 5) != 0)
        return (0);
    check_double_quotes(env);
    if (ft_strlen(env->line_splitted[1] - 2) > PROG_NAME_LENGTH)
        clean_exit(env, "Champion name too long (Max length 128)\n");
    env->name = ft_strdup(env->line_splitted[1]);
    return (1);
}

/*
** If format is ok, save champion's comment in env.
*/
int    checker_comment(t_env *env)
{
    if (ft_strncmp(env->line_splitted[0], ".comment", 8) != 0)
        return (0);
    check_double_quotes(env);
    if (ft_strlen(env->line_splitted[1] - 2) > COMMENT_LENGTH)
        clean_exit(env, "Champion comment is too long(Max length 2048)\n");
    env->comment = ft_strdup(env->line_splitted[1]);
    return (1);
}

/*
** Check if the line has 2 arguments
*/
void	check_len_tab(t_env *env)
{
    int i;

    i = 0;
    while(env->line_splitted[i])
        i++;
    if (i != 2)
        clean_exit(env, "Incorrect number of parameters for name or comment\n");
}

void	check_header(t_env *env, int fd)
{
    int     i;

    i = 0;
    while (i < 2)
    {
        if (get_next_line(fd, &env->line) > 0)
	    {
		    env->line_splitted = split_line(env, env->line, 0);
            if (env->line_splitted != NULL)
            {
				check_len_tab(env);
				if(!checker_name(env) && !checker_comment(env))
         			clean_exit(env, "Invalid comment or name\n");
				else
					i++;
            }
            clean_line_readed(env);
	    }
	    else
		    clean_exit(env, "Error : end of file\n");
    }
}
