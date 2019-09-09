/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:44:25 by advardon          #+#    #+#             */
/*   Updated: 2019/09/09 11:43:04 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check if the first section of the line is a label
** If true, return the name of the label.
*/

char	*check_label(char *str) //ajoter control orthographe
{
	int i;

	i = 0;
	while (str[i] && str[i] != ':')
	{
		i++;
		if (str[i] == ':')
			return (str);
	}
	return (NULL);
}

/*
** Check if the action name exists in of op.c
*/

char	*check_name_op(char *str, t_asm_line *instruction)
{
	int i;

	i = -1;
	while (++i < AVAILABLE_OPERATIONS)
	{
		if (ft_strcmp(str, g_op_tab[i].name) == 0)
		{
			instruction->operation = g_op_tab[i];
			return (str);
		}
	}
	clean_exit(NULL, "Unknown action\n");
	return (NULL);
}

/*
** Check if the nb of arguments for this action corresponds to op.c
*/

void	check_nb_arguments(char **tab, int nb_arg)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	if (i != nb_arg)
		clean_exit(NULL, "wrong nb of arguments\n");
	return ;
}

void	parsing(char *file, t_env *env)
{
	int		fd;
	char	*line;
	int		i;

	line = 0;
	i = 0;
	if (!(fd = open(file, O_RDONLY | O_NOFOLLOW)))
		clean_exit(NULL, "Opening file has failed\n");
	while (i < 2)
	{
		if (i == -1)
			clean_exit(NULL, "Champion doesn't have name or comment\n");
		i += create_header(env, fd, line);
	} //creer nlle struct asm_line
	while (get_next_line(fd, &line) > 0) //creer nlle struct asm_line
	{
		create_asm_line(env, line);
	}

	// PARSING DONE HERE, WRITING BINARY STARTS HERE


	free_env(env);
}
