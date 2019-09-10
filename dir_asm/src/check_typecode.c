/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:38:31 by advardon          #+#    #+#             */
/*   Updated: 2019/09/09 18:26:22 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Writing the code of each action type and moving it two bytes left
** for each parameter.
*/

void	def_type_code(t_asm_line *op)
{
	int i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		op->type_code = op->type_code << 2;
		op->type_code += op->params_type[i].type_code;
		i++;
	}
}

/*
** If no codetype is needed, add 1 bytes for action,  else add 2 bytes
** for action + typecode.
*/
void    check_typecode(t_asm_line *op)
{
    if (!op->operation.type_needed)
        op->line_len_bytes++;
    else
        op->line_len_bytes += 2;
	def_type_code(op);
}
