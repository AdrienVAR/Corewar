/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:17:22 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/02 10:26:39 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft/libft.h"
#include <unistd.h>

int				binary_read_integer(int fd, t_master *mstr)
{
	unsigned char	nb_str[4];
	int				read_ret;
	int				nb;
	int				i;

	nb = 0;
	ft_bzero(nb_str, 4);
	read_ret = read(fd, &nb_str, 4);
	if (read_ret != 4)
		exit_program(mstr);
	i = -1;
	while (++i < 4)
		nb += (nb << 8) + nb_str[i];
	return (nb);
}
