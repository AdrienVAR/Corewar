/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:17:22 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/05 10:31:21 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include <unistd.h>

int		binary_read_integer(int fd, t_master *mstr)
{
	char			nb_str[4];
	int				read_ret;
	t_int_cast 		caster;
	int				i;

	caster.nb = 0;
	ft_bzero(nb_str, 4);
	read_ret = read(fd, &nb_str, 4);
	if (read_ret != 4)
		exit_program(mstr);
	i = -1;
	while (++i < 4)
		caster.casted[i] = (unsigned char)nb_str[3 - i];
	return (caster.nb);
}

void	binary_read_string(int fd, char *str, int sz, t_master *mstr)
{
	int				read_ret;
	int				nb;

	nb = 0;
	ft_bzero(str, sz + 1);
	read_ret = read(fd, str, sz);
	if (read_ret != sz)
	{
		str = 0;
		exit_program(mstr);
	}
}

void	binary_read_null(int fd, t_master *mstr)
{
	int zero;

	if ((zero = binary_read_integer(fd, mstr)))
		exit_program(mstr);
}
