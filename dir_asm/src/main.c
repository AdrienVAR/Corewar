/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:41:23 by advardon          #+#    #+#             */
/*   Updated: 2019/09/30 11:28:14 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	t_env *env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		clean_exit(-1, env, "Error: Memory allocation failed\n");
	if (argc != 2 || !check_extention(argv[1]))
		clean_exit(-1, env, "Usage: ./asm <sourcefile.s>\n");
	parsing(argv[1], env);
	writing(argv[1], env);
	env->num_line = -1;
	clean_exit(-1, env, "");
	return (0);
}
