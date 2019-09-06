/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:38:31 by advardon          #+#    #+#             */
/*   Updated: 2019/09/06 14:40:02 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check if there is a value, that contains only digits, and record it.
** Check if it is a REG that parameter value is >0 and <= REG_NUMBER.
*/

void	param_digit_value(t_asm_line *instruction, int param, char *str)
{
	int i;

	i = 0;
	if (!str[i])
		clean_exit(NULL, "Missing value on parameter\n");
	while(str[i])
	{
		if (!(ft_isdigit(str[i])) && (str[i] != '-' && str[i] != '+' && str[i] != ',')) //todel ','
			clean_exit(NULL, "parameter is not a number\n");
		i++;
	}
	instruction->param_value[param] = ft_atoi(str);
    if (instruction->params_type[param].type == g_type[0].type)
        if (instruction->param_value[param] < 1 || instruction->param_value[param] > REG_NUMBER)
            clean_exit(NULL, "invalid register number\n");
}

/*
** Check if the type used for each parameter is a valid type. Use of a binary
** mask to verify if it fits with types from g_op_table
*/

void	check_valid_type(t_asm_line *instruction, int param)
{
	if (!(instruction->operation.params_type[param] & instruction->params_type[param].type))
		clean_exit(NULL, "Invalid argument type for this action\n");
}

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

void	check_action_type(t_asm_line *instruction)
{
	int i;
	int param;

	param = 0;
	if (instruction->label == NULL)
		i = 1;
	else
		i = 2;
	while (instruction->line_splitted[i])
	{
		if (instruction->line_splitted[i][0] == '%')
		{
			if (instruction->line_splitted[i][1]
			&& (instruction->line_splitted[i][1] == ':'))
			{
				instruction->params_type[param] = g_type[3];
				check_valid_type(instruction, param);
			}
			instruction->params_type[param] = g_type[1];
            instruction->line_len_bytes += DIR_SIZE;
			param_digit_value(instruction, param, instruction->line_splitted[i] + 1);
			check_valid_type(instruction, param);
		}
		else if (instruction->line_splitted[i][0] == ':')
		{
				instruction->params_type[param] = g_type[3];
				check_valid_type(instruction, param);
		}
		else if (instruction->line_splitted[i][0] == 'r')
		{
			instruction->params_type[param] = g_type[0];
            instruction->line_len_bytes += REG_SIZE;
			param_digit_value(instruction, param, instruction->line_splitted[i] + 1);
			check_valid_type(instruction, param);
		}
		else
		{
			instruction->params_type[param] = g_type[2];
            instruction->line_len_bytes += IND_SIZE;
			param_digit_value(instruction, param, instruction->line_splitted[i] + 1);
			check_valid_type(instruction, param);
		}
		i++;
		param++;
	}
    lenline_opcode_typecode(instruction);
}