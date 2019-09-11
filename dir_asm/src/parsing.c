/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:44:25 by advardon          #+#    #+#             */
/*   Updated: 2019/09/11 11:17:25 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parsing(char *file, t_env *env)
{
	if (!(env->fd = open(file, O_RDONLY | O_NOFOLLOW)))
		clean_exit(env, "Error: Opening file has failed\n");
	check_header(env);
	check_asm(env);
	if (close(env->fd) == -1)
		clean_exit(env, "Error: Closing file has failed\n");
	fill_label(env);
}
