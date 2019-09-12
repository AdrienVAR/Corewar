/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:12:40 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/12 10:53:35 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

long int	ft_atol(const char *str)
{
	long int nb;
	long int sg;

	nb = 0;
	sg = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '+' || *str == '-')
		sg = *str++ == '+' ? 1 : -1;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + (*str++ - '0');
	return (nb * sg);
}

/*
** Check if the type used for each parameter is a valid type. Use of a binary
** mask to verify if it fits with types from g_op_table
*/

void		check_digits(t_env *env, t_asm_line *op, int param, char *str)
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
	op->param_value[param] = ft_atol(str);
	if (op->params_type[param].type == g_type[0].type)
		if (op->param_value[param] < 1 || op->param_value[param] > REG_NUMBER)
			clean_exit(env, "Error: invalid register number\n");
}
