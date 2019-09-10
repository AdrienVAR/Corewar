/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:30:26 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/10 16:22:01 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_magic_header(int fd)
{
	int			i;
	t_int_cast 	magic_nb;

	i = 3;
	magic_nb.nb = COREWAR_EXEC_MAGIC;
	while (i >= 0)
	{
		ft_putchar_fd(magic_nb.casted[i], fd);
		i--;
	}
}

void	writing(char *file, t_env *env)
{
	int		fd;
	char	*tmp;
	char	*new_file;

	new_file = ft_strndup(file, ft_strlen(file) - 2);
	tmp = ft_strjoin("./", new_file);
	free(new_file);
	new_file = ft_strjoin(tmp, ".cor");
	free(tmp);
	if ((fd = open(new_file, O_CREAT | O_WRONLY | O_TRUNC, 0600)) == -1)
		clean_exit(env, "Opening/Creating new file has failed\n");
	free(new_file);
	write_magic_header(fd);
	if (close(fd) == -1)
		clean_exit(env, "Closing new file has failed\n");
}
