/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:15:22 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/10 14:19:47 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		find_label(t_env *env, char *label, int pos)
{
	t_asm_line *current;

	current = env->head;
	while (current)
	{
		if (current->label)
		{
			if (ft_strcmp(current->label, label) == 0)
				return (current->line_pos_bytes - pos);
		}
		current = current->next;
	}
	clean_exit(env, "label not existing\n");
	return (0);
}

void	fill_label(t_env *env)
{
	int i;
	t_asm_line *current;

	current = env->head;
	while (current)
	{
		i = -1;
		while (++i < 4)
		{
			if (current->param_label[i])
				current->param_value[i] = find_label(env,
					current->param_label[i], current->line_pos_bytes);
		}
		current = current->next;
	}
}
