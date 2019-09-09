/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:12:40 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/09 18:28:01 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check if the type used for each parameter is a valid type. Use of a binary
** mask to verify if it fits with types from g_op_table
*/
void	check_valid_type(t_asm_line *instruction, int param, t_env *env)
{
	if (!(instruction->operation.params_type[param] &
		instruction->params_type[param].type))
		clean_exit(env, "Invalid argument type for this action\n");
}

void	check_digits(t_env *env, t_asm_line *instruction, int param, char *str)
{
	int i;

	i = 0;
	if ((instruction->params_type[param].type == g_type[0].type)
		|| (instruction->params_type[param].type == g_type[1].type))
		str++;
	if (!str[i])
		clean_exit(env, "Missing value on parameter\n");
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			clean_exit(env, "parameter is not a number\n");
		i++;
	}
	instruction->param_value[param] = ft_atoi(str);
	if (instruction->params_type[param].type == g_type[0].type)
        if (instruction->param_value[param] < 1 || instruction->param_value[param] > REG_NUMBER)
            clean_exit(env, "invalid register number\n");
}

/*
** Check if the nb of arguments for this action corresponds to op.c
*/
void	check_arguments(t_env *env, t_asm_line *instruction)
{
    int i;
    int k;
	int param;

    i = 0;
    k = (instruction->label != NULL) ? 2 : 1;
	while (env->line_splitted[i])
		i++;
	if (i - k != instruction->operation.nb_params)
		clean_exit(env, "wrong nb of arguments\n");
	param = 0;
	while (k < i)
	{
		if (env->line_splitted[k][0] == DIRECT_CHAR)
		{
			if (env->line_splitted[k][1] && (env->line_splitted[k][1] == LABEL_CHAR))
				instruction->params_type[param] = g_type[3];
			else
			{
				instruction->params_type[param] = g_type[1];
            	instruction->line_len_bytes += DIR_SIZE;
			}
		}
		else if (env->line_splitted[k][0] == LABEL_CHAR)
			instruction->params_type[param] = g_type[3];
		else if (env->line_splitted[k][0] == 'r')
		{
			instruction->params_type[param] = g_type[0];
            instruction->line_len_bytes += REG_SIZE;
		}
		else
		{
			instruction->params_type[param] = g_type[2];
            instruction->line_len_bytes += IND_SIZE;
		}
		check_digits(env, instruction, param, env->line_splitted[k]);
		check_valid_type(instruction, param, env);
		param++;
		k++;
	}
}

/*
** Check if the action name exists in of op.c
*/
void	check_name_op(t_env *env, t_asm_line *instruction)
{
	int i;
    int k;

	i = -1;
    k = (instruction->label != NULL) ? 1 : 0;
	while (++i < AVAILABLE_OPERATIONS)
	{
		if (ft_strcmp(env->line_splitted[k], g_op_tab[i].name) == 0)
		{
            instruction->name_operations = env->line_splitted[k];
			instruction->operation = g_op_tab[i];
			check_arguments(env, instruction);
            return;
		}
	}
	clean_exit(env, "Unknown action\n");
}
