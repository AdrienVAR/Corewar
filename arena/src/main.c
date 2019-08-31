/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/31 16:09:27 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "arena.h"

int				main(int argc, char **argv)
{
	t_master	*mstr;

	if (!(--argc))
		ft_putstr(USAGE_STR);
	mstr = 0;
	init(&mstr);
	file_loading(mstr, argc, argv);
	return (0);
}
