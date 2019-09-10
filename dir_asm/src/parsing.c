/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:44:25 by advardon          #+#    #+#             */
/*   Updated: 2019/09/10 14:17:10 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parsing(char *file, t_env *env)
{
	int		fd;

	if (!(fd = open(file, O_RDONLY | O_NOFOLLOW)))
		clean_exit(env, "Opening file has failed\n");
	check_header(env, fd);
	check_asm(env, fd);
	if (close(fd) == -1)
		clean_exit(env, "Closing file has failed\n");
	fill_label(env);
}
