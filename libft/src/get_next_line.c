/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:40:14 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/12 15:04:56 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

static int		ft_free_return(char **gnl, int val)
{
	if (*gnl)
		ft_memdel((void **)gnl);
	return (val);
}

static int		ft_complete_line(char **gnl, int fd, char *buf, int *r)
{
	char		*temp;

	while (!ft_strchr(gnl[fd], '\n') && (*r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		temp = gnl[fd];
		gnl[fd] = ft_strjoin(gnl[fd], buf);
		free(temp);
		if (!gnl[fd])
			return (0);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*gnl[MAX_FD] = {0};
	char		buf[BUFF_SIZE + 1];
	int			r;
	char		*temp;

	r = 0;
	if (fd < 0 || fd >= MAX_FD || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(gnl[fd] = !gnl[fd] ? ft_strnew(0) : gnl[fd]))
		return (-1);
	*line = 0;
	ft_bzero(buf, BUFF_SIZE + 1);
	if (!ft_complete_line(gnl, fd, buf, &r))
		return (-1);
	if (r == -1 || (!r && !*gnl[fd]))
		return (ft_free_return(&gnl[fd], r == -1 ? -1 : 0));
	temp = ft_strchr(gnl[fd], '\n');
	r = !temp ? (ft_strlen(gnl[fd])) : temp - gnl[fd];
	if ((*line = ft_strnew(r)))
		ft_memcpy(*line, gnl[fd], r);
	ft_strcpy(gnl[fd], temp ? temp + 1 : "");
	if (!*line)
		return (ft_free_return(&gnl[fd], -1));
	return (1);
}
