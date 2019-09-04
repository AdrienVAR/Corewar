/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:55:51 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/04 12:23:17 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int not_a_comment_or_empty(char *line)
{
	int i;

	i = 0;
	if (line[0] == "\0")
		return (0);
	while((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
	if (line[i] == '#')
		return (0);

	return (1);
}

int check_name(char *line)
{
	int i;

	i = 0;
	while((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
	
}

check_comment()
{
	int i;

	i = 0;
	while((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
}

void	parsing(char *file, t_env *env)
{
	int		fd;
	char	*line;
	int 	i;

	if (!(fd = open(file, O_RDONLY | O_NOFOLLOW)))
		clean_exit(NULL, "Opening file has failed\n");
	while (!env->name || !env->comment)
	{
		if (get_next_line(fd, &line)) == 0)
			clean_exit(NULL, "name or comment missing\n");
		if (not_a_comment_or_empty(line))
		{
			i = 0;
			while((line[i] == ' ' || line[i] == '\t') && line[i])
				i++;
			if (line[i] == '.' && line[i + 1] == 'n' && line[i + 2] == 'a'
				&& line[i + 3] == 'm' && line[i + 4] == 'e')
				check_name(line, env);
			else if (line[i] == '.' && line[i + 1] == 'c' && line[i + 2] == 'o'
				&& line[i + 3] == 'm' && line[i + 4] == 'm' && line[i + 5] == 'e'
					&& line[i + 6] == 'n' && line[i + 7] == 't')
				check_comment(line, env);
			else
				clean_exit(NULL, "wrong input\n");
		}
	}


	if ((close(fd) == -1))
		clean_exit(NULL, "Closing file has failed\n");
}
