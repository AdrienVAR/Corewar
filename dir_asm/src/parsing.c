/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:44:25 by advardon          #+#    #+#             */
/*   Updated: 2019/09/05 16:10:05 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "asm.h"

/*
** Check if the first section of the line is a label
** If true, return the name of the label.
*/

char	*check_label(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ':')
	{
		i++;
		if (str[i] == ':')
			return (str);
	}
	return (NULL);
}

/*
** Check if the action name exists in of op.c
*/

char	*check_name_op(char *str, t_asm_line *instruction)
{
	int i;

	i = 0;
	while (i++ < AVAILABLE_OPERATIONS)
	{
		if (ft_strcmp(str, g_op_tab[i].name) == 0)
		{
			instruction->operation = g_op_tab[i];
			return (str);
		}
	}
	clean_exit(NULL, "Unknown action\n");
	return (NULL);
}

/*
** Check if the nb of arguments for this action corresponds to op.c
*/

void	check_nb_arguments(char **tab, int nb_arg)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	if (i != nb_arg)
		clean_exit(NULL, "wrong nb of arguments\n");
	return ;
}

void	param_digit_value(t_asm_line *instruction, int param, char *str)
{
	int i;

	i = 0;
	if (!str[i])
		clean_exit(NULL, "Missing value on parameter\n");
	while(str[i])
	{
		if (!(ft_isdigit(str[i])) && (str[i] != '-' && str[i] != '+' && str[i] != ',')) //todel
			clean_exit(NULL, "arguments is not a number\n");
		i++;
	}
	instruction->param_value[param] = ft_atoi(str);
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
			}
			instruction->params_type[param] = g_type[1];
			param_digit_value(instruction, param, instruction->line_splitted[i] + 1);
		}
		else if (instruction->line_splitted[i][0] == ':')
		{
				instruction->params_type[param] = g_type[3];
		}
		else if (instruction->line_splitted[i][0] == 'r')
		{
			instruction->params_type[param] = g_type[0];
			param_digit_value(instruction, param, instruction->line_splitted[i] + 1);
		}
		else
		{
			instruction->params_type[param] = g_type[2];
			param_digit_value(instruction, param, instruction->line_splitted[i] + 1);
		}
		i++;
		param++;
	}
}

void	def_type_code(t_asm_line *instruction)
{
	int i;
	int byte_mov;

	i = 0;
	byte_mov = 2;
	while(i < MAX_ARGS_NUMBER)
	{
		instruction->type_code = instruction->type_code << byte_mov;
		instruction->type_code += instruction->params_type[i].type_code;
		i++;
		//byte_mov = byte_mov + 2;
	}
}

void	parsing(char *file, t_env *env)
{
	int		fd;
	char	*line;
	char 	**tab;
	t_asm_line	*head;
	t_asm_line	*instruction;

	(void) env;
	tab = NULL;
	if (!(fd = open(file, O_RDONLY | O_NOFOLLOW)))
		clean_exit(NULL, "Opening file has failed\n");
	line = 0;
	get_next_line(fd, &line);
	if (!(tab = split_line(line, 0)))
		return ;
	head = NULL;
	(void) file;
	//get_file_content(file);
	instruction = ft_lstadd_end(head);
	instruction->line_splitted = tab;
	instruction->label = check_label(tab[0]);
	if (instruction->label)
	{
		instruction->name_operations = check_name_op(tab[1], instruction);
		check_nb_arguments(tab + 2, instruction->operation.nb_params);
	}
	else
	{
		instruction->name_operations = check_name_op(tab[0], instruction);
		check_nb_arguments(tab + 1, instruction->operation.nb_params);
	}
	check_action_type(instruction);
	def_type_code(instruction);
	ft_putstr(instruction->name_operations);
}

/*void	parsing(char *file)
{
	head = NULL;
	(void) file;
	//get_file_content(file);
	instruction = ft_lstadd_end(head);
	instruction->line_splitted = instruct;
	//instruction->label = check_label();
	ft_putstr(instruction->line_splitted[2]);
}*/

/*
** Create a new struct and add it at end of the list.
*/

t_asm_line	*ft_lstadd_end(t_asm_line *lst)
{
	t_asm_line	*lstnew;
	t_asm_line	*lnext;

	if (!(lstnew = (t_asm_line *)ft_memalloc(sizeof(t_asm_line))))
		return (NULL);
	if (!lst)
		return (lstnew);
	lstnew->next = NULL;
	lnext = lst;
	while (lnext->next)
		lnext = lnext->next;
	lnext->next = lstnew;
	return (lst);
}

/* char type = 0
type = IND_CODE
type = type << 2
type &= REG_CODE 
*/