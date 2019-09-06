/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:44:25 by advardon          #+#    #+#             */
/*   Updated: 2019/09/06 10:58:50 by advardon         ###   ########.fr       */
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

void	parsing(char *file, t_env *env)
{
	int		fd;
	char	*line;
	t_asm_line	*head;
	t_asm_line	*instruction;

	(void) env;
	head = NULL;
	line = 0;
	(void) file;
	if (!(fd = open(file, O_RDONLY | O_NOFOLLOW)))
		clean_exit(NULL, "Opening file has failed\n");
	instruction = ft_lstadd_end(head);
	get_next_line(fd, &line);
	if (!(instruction->line_splitted = split_line(line, 0)))
		return ;
	instruction->label = check_label(instruction->line_splitted[0]);
	if (instruction->label)
	{
		instruction->name_operations = check_name_op(instruction->line_splitted[1], instruction);
		check_nb_arguments(instruction->line_splitted + 2, instruction->operation.nb_params);
	}
	else
	{
		instruction->name_operations = check_name_op(instruction->line_splitted[0], instruction);
		check_nb_arguments(instruction->line_splitted + 1, instruction->operation.nb_params);
	}
	check_action_type(instruction);
	def_type_code(instruction);
	ft_putstr(instruction->name_operations);
}

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
