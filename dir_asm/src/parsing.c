/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:55:51 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/04 15:37:49 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** get_file_content : Get file content into the buffer
*/

char	*get_file_content(char *file)
{
	int		fd;
	char	*line;
	char 	*buffer;

	if (!(fd = open(file, O_RDONLY | O_NOFOLLOW)))
		clean_exit(NULL, "Opening file has failed\n");
	if (!(buffer = ft_strdup("\0")))
		clean_exit(NULL, "Memory allocation has failed\n");
	while (get_next_line(fd, &line) == 1)
	{
		if (!(buffer = ft_strjoin_free(buffer, line)))
			clean_exit(buffer, "Memory allocation has failed\n");
		ft_strdel(&line);
	}
	if ((close(fd) == -1))
		clean_exit(buffer, "Closing file has failed\n");
	return (buffer);
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