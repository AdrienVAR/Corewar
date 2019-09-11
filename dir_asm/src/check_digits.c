/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:12:40 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/11 11:09:37 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check if the type used for each parameter is a valid type. Use of a binary
** mask to verify if it fits with types from g_op_table
*/

void	check_digits(t_env *env, t_asm_line *op, int param, char *str)
{
	int i;

	i = 0;
	if ((op->params_type[param].type == g_type[0].type)
		|| (op->params_type[param].type == g_type[1].type))
		str++;
	if (!str[i])
		clean_exit(env, "Error: Missing value on parameter\n");
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			clean_exit(env, "Error: parameter is not a number\n");
		i++;
	}
	op->param_value[param] = ft_atoi(str);
	if (op->params_type[param].type == g_type[0].type)
		if (op->param_value[param] < 1 || op->param_value[param] > REG_NUMBER)
			clean_exit(env, "Error: invalid register number\n");
}
