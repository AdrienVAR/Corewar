/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:41:23 by advardon          #+#    #+#             */
/*   Updated: 2019/08/30 15:04:08 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		main(int argc, char **argv)
{
	if (argc != 2 || !check_extention(argv[1]))
		clean_exit(NULL, "Usage: ./asm <sourcefile.s>\n");
	parsing(argv[1]);
	return (0);
}
