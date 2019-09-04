/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:41:23 by advardon          #+#    #+#             */
/*   Updated: 2019/09/04 11:52:33 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	t_env env;

	if (argc != 2 || !check_extention(argv[1]))
		clean_exit(NULL, "Usage: ./asm <sourcefile.s>\n");
	parsing(argv[1], &env);
	return (0);
}
