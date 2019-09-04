/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:55:51 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/04 16:15:47 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
int not_a_comment_or_empty(char *line)
{
	int i;

	i = 0;
	if (line[0] == "\0")
		return (0);
	while((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
	if (line[i] == '#')
		return (0);

	return (1);
}

int check_name(char *line)
{
	int i;

	i = 0;
	while((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
	
}

check_comment()
{
	int i;

	i = 0;
	while((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
}*/

void	parsing(char *file, t_env *env)
{
	int		fd;
	char	*line;
	char 	**tab;
	t_asm_line	*head;
	t_asm_line	*instruction;

	(void) env;
	if (!(fd = open(file, O_RDONLY | O_NOFOLLOW)))
		clean_exit(NULL, "Opening file has failed\n");

	get_next_line(fd, &line);
	tab = split_line(line, 0);

	head = NULL;
	(void) file;
	//get_file_content(file);
	instruction = ft_lstadd_end(head);
	instruction->line_splitted = tab;
	//instruction->label = check_label();
	ft_putstr(instruction->line_splitted[1]);
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

/* type = 0
type = T_IND
type = type << 2
type &= T_REG */