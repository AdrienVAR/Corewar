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

void	def_type_code(t_asm_line *instruction)
{
	int i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		instruction->type_code = instruction->type_code << 2;
		instruction->type_code += instruction->params_type[i].type_code;
		i++;
	}
}

/*
** If no codetype is needed, add 1 bytes for action, else add 2 bytes
** for action + typecode.
*/

void    lenline_opcode_typecode(t_asm_line *instruction)
{
    if (!instruction->operation.type_needed)
        instruction->line_len_bytes++;
    else
        instruction->line_len_bytes += 2;
}
