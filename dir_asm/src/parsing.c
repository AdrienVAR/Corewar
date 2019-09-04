/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:55:51 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/04 16:04:14 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
}

void	parsing(char *file, t_env *env)
{
	int		fd;
	char	*line;
	int 	i;

	if (!(fd = open(file, O_RDONLY | O_NOFOLLOW)))
		clean_exit(NULL, "Opening file has failed\n");
	while (!env->name || !env->comment)
	{
		if (get_next_line(fd, &line)) == 0)
			clean_exit(NULL, "name or comment missing\n");
		if (not_a_comment_or_empty(line))
		{
			i = 0;
			while((line[i] == ' ' || line[i] == '\t') && line[i])
				i++;
			if (line[i] == '.' && line[i + 1] == 'n' && line[i + 2] == 'a'
				&& line[i + 3] == 'm' && line[i + 4] == 'e')
				check_name(line, env);
			else if (line[i] == '.' && line[i + 1] == 'c' && line[i + 2] == 'o'
				&& line[i + 3] == 'm' && line[i + 4] == 'm' && line[i + 5] == 'e'
					&& line[i + 6] == 'n' && line[i + 7] == 't')
				check_comment(line, env);
			else
				clean_exit(NULL, "wrong input\n");
		}
	}

void	parsing(char *file)
{
	t_asm_line	*head;
	t_asm_line	*instruction;
	char		*instruct[4];

	instruct[0] = "arriere:";
	instruct[1] = "ld";
	instruct[2] = "%-5";
	instruct[3] = "r5";
	instruct[4][0] = '\0';

	head = NULL;
	(void) file;
	//get_file_content(file);
	instruction = ft_lstadd_end(head);
	instruction->line_splitted = instruct;
	//instruction->label = check_label();
	ft_putstr(instruction->line_splitted[2]);
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

/* type = 0
type = T_IND
type = type << 2
type &= T_REG */