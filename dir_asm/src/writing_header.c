/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:44:58 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/11 11:18:18 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_magic_header(int fd)
{
	int			i;
	t_int_cast	magic_nb;

	i = 3;
	magic_nb.nb = COREWAR_EXEC_MAGIC;
	while (i >= 0)
	{
		ft_putchar_fd(magic_nb.casted[i], fd);
		i--;
	}
}

void	write_name(char *name, int fd)
{
	int i;
	int	remaining;

	i = 0;
	while (name[i])
		ft_putchar_fd(name[i++], fd);
	remaining = PROG_NAME_LENGTH - i + 4;
	while (remaining > 0)
	{
		ft_putchar_fd('\0', fd);
		remaining--;
	}
}

void	write_champion_size(int size, int fd)
{
	int			i;
	t_int_cast	champion_size;

	i = 3;
	champion_size.nb = size;
	while (i >= 0)
	{
		ft_putchar_fd(champion_size.casted[i], fd);
		i--;
	}
}

void	write_comment(char *comment, int fd)
{
	int i;
	int	remaining;

	i = 0;
	while (comment[i])
		ft_putchar_fd(comment[i++], fd);
	remaining = COMMENT_LENGTH - i + 4;
	while (remaining > 0)
	{
		ft_putchar_fd('\0', fd);
		remaining--;
	}
}

void	writing_header(t_env *env, int fd)
{
	write_magic_header(fd);
	write_name(env->name, fd);
	write_champion_size(env->position_binary, fd);
	write_comment(env->comment, fd);
}
