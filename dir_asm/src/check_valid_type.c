/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:12:40 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/10 15:14:10 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check if the type used for each parameter is a valid type. Use of a binary
** mask to verify if it fits with types from g_op_table
*/
void	check_valid_type(t_asm_line *op, int param, t_env *env)
{
	if (!(op->operation.params_type[param] &
		op->params_type[param].type))
		clean_exit(env, "Invalid argument type for this action\n");
}
