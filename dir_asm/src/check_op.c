/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:12:40 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/10 15:14:10 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label_case(t_env *env, t_asm_line *op, int param, int k)
{
	if (env->line_splitted[k][0] == DIRECT_CHAR)
	{
		check_syntax_label(env, env->line_splitted[k] + 2);
		op->params_type[param] = g_type[1];
		op->line_len_bytes += op->operation.dir_size;
		op->param_label[param] = ft_strndup(env->line_splitted[k] + 2,
			ft_strlen(env->line_splitted[k]) + 2);
	}
	else
	{
		check_syntax_label(env, env->line_splitted[k] + 1);
		op->params_type[param] = g_type[2];
		op->line_len_bytes += IND_SIZE;
		op->param_label[param] = ft_strndup(env->line_splitted[k] + 1,
			ft_strlen(env->line_splitted[k]) + 1);
	}
}

void	non_label_case(t_env *env, t_asm_line *op, int param, int k)
{
	if (env->line_splitted[k][0] == DIRECT_CHAR)
	{
		op->params_type[param] = g_type[1];
     	op->line_len_bytes += op->operation.dir_size;
	}
	else if (env->line_splitted[k][0] == 'r')
	{
		op->params_type[param] = g_type[0];
		op->line_len_bytes += REG_SIZE;
	}
	else
	{
		op->params_type[param] = g_type[2];
		op->line_len_bytes += IND_SIZE;
	}
	check_digits(env, op, param, env->line_splitted[k]);
}

/*
** check number or arguments
** check if arguments are valid
*/
void	check_arguments(t_env *env, t_asm_line *op)
{
    int i;
    int k;
	int param;

    i = 0;
    k = (op->label != NULL) ? 2 : 1;
	while (env->line_splitted[i])
		i++;
	if (i - k != op->operation.nb_params)
		clean_exit(env, "wrong nb of arguments\n");
	param = 0;
	while (k < i)
	{
		if (env->line_splitted[k][0] == LABEL_CHAR || (env->line_splitted[k][0]
			== DIRECT_CHAR && env->line_splitted[k][1] == LABEL_CHAR))
			label_case(env, op, param, k);
		else 
			non_label_case(env, op, param, k);
		check_valid_type(op, param, env);
		param++;
		k++;
	}
}

/*
** Check if the action name exists in of op.c
*/
void	check_op(t_env *env, t_asm_line *op)
{
	int i;
    int k;

	i = -1;
    k = (op->label != NULL) ? 1 : 0;
	while (++i < AVAILABLE_OPERATIONS)
	{
		if (ft_strcmp(env->line_splitted[k], g_op_tab[i].name) == 0)
		{
			op->operation = g_op_tab[i];
			op->line_pos_bytes = env->position_binary;
			check_arguments(env, op);
            return;
		}
	}
	clean_exit(env, "Unknown action\n");
}
