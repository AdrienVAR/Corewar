/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:55:51 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/02 11:16:59 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** get_file_content : Get file content into the buffer
*/

char	*get_file_content(char *file)
{
	int		fd;
	char	*line;
	char 	*buffer;

	if (!(fd = open(file, O_RDONLY | O_NOFOLLOW)))
		clean_exit(NULL, "Opening file has failed\n");
	if (!(buffer = ft_strdup("\0")))
		clean_exit(NULL, "Memory allocation has failed\n");
	while (get_next_line(fd, &line) == 1)
	{
		if (!(buffer = ft_strjoin_free(buffer, line)))
			clean_exit(buffer, "Memory allocation has failed\n");
		ft_strdel(&line);
	}
	if ((close(fd) == -1))
		clean_exit(buffer, "Closing file has failed\n");
	return (buffer);
}

void	parsing(char *file)
{
	char 	*buffer;

	buffer = get_file_content(file);
	ft_putstr(buffer);
}
