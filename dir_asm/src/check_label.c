/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:33:24 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/10 14:33:10 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check if the first section of the line is a label
** if true -> return 1
** if false -> return 0
**
** Check if all chars are valid (in LABEL_CHARS)
** if false -> exit
*/

void	check_label(t_env *env, t_asm_line *instruction)
{
	int i;
	int j;
	int k;

	i = 0;
	while (env->line_splitted[0][i])
        i++;
    if (env->line_splitted[0][i - 1] != LABEL_CHAR)
		return;
	i = 0;
	while (env->line_splitted[0][i] != LABEL_CHAR)
	{
		k = 0;
		j = 0;
		while (LABEL_CHARS[j])
		{
			if (env->line_splitted[0][i] == LABEL_CHARS[j])
				k = 1;
			j++;
		}
		if (k == 0)
			clean_exit(env, "Wrong syntax for Label\n");
		i++;
	}
	instruction->label = ft_strndup(env->line_splitted[0], ft_strlen(env->line_splitted[0]) - 1);
}
