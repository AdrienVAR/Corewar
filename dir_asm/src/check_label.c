/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:33:24 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/30 11:32:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft/ft_printf.h"

/*
** Check if the first section of the line is a label
** if true -> return 1
** if false -> return 0
**
** Check if all chars are valid (in LABEL_CHARS)
** if false -> exit
*/

static void	check_same_labels(t_env *env, char *label)
{
	int			counter;
	t_asm_line	*line;

	line = env->head;
	if (!line || !label)
		return ;
	counter = 0;
	while (line)
	{
		if (line->label
		&& !ft_strncmp(line->label, label, ft_strlen(label) - 1))
			counter++;
		line = line->next;
	}
	if (counter)
	{
		ft_printf("Line %2.0~%d%~ => label [%2.0~%.*s%~]",
				env->num_line, ft_strlen(label) - 1, label);
		ft_printf(" appearing for the %d time will be ignored\n",
				counter + 1);
	}
}

void		check_syntax_label(t_env *env, char *label)
{
	int i;
	int j;
	int k;

	i = 0;
	while (label[i] && label[i] != LABEL_CHAR)
	{
		k = 0;
		j = 0;
		while (LABEL_CHARS[j])
		{
			if (label[i] == LABEL_CHARS[j])
				k = 1;
			j++;
		}
		if (k == 0)
			clean_exit(-1, env, "Wrong syntax for Label\n");
		i++;
	}
}

int			check_label(t_env *env, t_asm_line *op)
{
	int i;

	i = 0;
	while (env->line_splitted[0][i])
		i++;
	if (env->line_splitted[0][i - 1] != LABEL_CHAR)
		return (1);
	check_syntax_label(env, env->line_splitted[0]);
	check_same_labels(env, env->line_splitted[0]);
	op->label = ft_strndup(env->line_splitted[0],
		ft_strlen(env->line_splitted[0]) - 1);
	if (env->line_splitted[1] == NULL)
	{
		op->line_len_bytes = 0;
		op->line_pos_bytes = env->position_binary;
		return (0);
	}
	else
		return (1);
}
