/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:15:22 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/11 11:16:04 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm_line		*find_label(t_env *env, char *label)
{
	t_asm_line *current;

	current = env->head;
	while (current)
	{
		if (current->label)
		{
			if (ft_strcmp(current->label, label) == 0)
			{
				while (current && current->line_len_bytes == 0)
					current = current->next;
				if (!current)
					clean_exit(env, "Error: label doesn't match\n");
				return (current);
			}
		}
		current = current->next;
	}
	clean_exit(env, "Error: label not existing\n");
	return (NULL);
}

void			fill_label(t_env *env)
{
	int			i;
	t_asm_line	*current;
	t_asm_line	*target;

	current = env->head;
	while (current)
	{
		i = -1;
		while (++i < 4)
		{
			if (current->param_label[i])
			{
				target = find_label(env, current->param_label[i]);
				current->param_value[i] = target->line_pos_bytes
					- current->line_pos_bytes;
			}
		}
		current = current->next;
	}
}
