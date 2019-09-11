/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:41:23 by advardon          #+#    #+#             */
/*   Updated: 2019/09/11 11:17:17 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	t_env *env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		clean_exit(env, "Error: Memory allocation failed\n");
	if (argc != 2 || !check_extention(argv[1]))
		clean_exit(env, "Usage: ./asm <sourcefile.s>\n");
	parsing(argv[1], env);
	writing(argv[1], env);
	clean_exit(env, "Success: Writing output...\n");
}
