/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:05:00 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/30 13:06:56 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"

void	clean_line_readed(t_env *env)
{
	int i;

	i = 0;
	while (env->line_splitted && env->line_splitted[i])
		ft_memdel((void**)&(env->line_splitted[i++]));
	if (env->line_splitted)
		ft_memdel((void**)&env->line_splitted);
	if (env->line)
		ft_memdel((void**)&env->line);
}

void	free_env(t_env *env)
{
	if (env->name)
		ft_memdel((void**)&env->name);
	if (env->comment)
		ft_memdel((void**)&env->comment);
	ft_bzero(env, sizeof(t_env));
	ft_memdel((void**)&env);
}

void	clean_param_label(t_asm_line *instruction)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (instruction->param_label[i])
			ft_memdel((void**)&(instruction->param_label[i]));
		i++;
	}
}

void	clean_exit(int col, t_env *env, char *error_message)
{
	t_asm_line *tmp;

	if (env)
	{
		if (env->fd)
			get_next_line(-2, &env->line);
		clean_line_readed(env);
		if (env->num_line > 0)
			ft_printf("line %d - ", env->num_line);
		if (col != -1)
			ft_printf("col %d : ", col);
		while (env->head)
		{
			tmp = env->head->next;
			if (env->head->label)
				ft_memdel((void**)&(env->head->label));
			clean_param_label(env->head);
			ft_bzero(env->head, sizeof(t_asm_line));
			ft_memdel((void**)&env->head);
			env->head = tmp;
		}
		free_env(env);
	}
	ft_putstr(error_message);
	exit(0);
}
