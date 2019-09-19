/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:59:32 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/19 11:37:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft/get_next_line.h"

/*
** Create a new struct and add it at end of the list.
*/

t_asm_line	*ft_lstadd_end(t_asm_line **lst, t_env *env)
{
	t_asm_line	*lstnew;
	t_asm_line	*lnext;
	t_asm_line	*lstart;

	lstart = *lst;
	if (!(lstnew = (t_asm_line *)ft_memalloc(sizeof(t_asm_line))))
		clean_exit(env, "Error: memory allocation failed\n");
	if (!lstart)
	{
		lstart = lstnew;
		*lst = lstart;
		return (lstnew);
	}
	lstnew->next = NULL;
	lnext = lstart;
	while (lnext->next)
		lnext = lnext->next;
	lnext->next = lstnew;
	*lst = lstart;
	return (lstnew);
}

void		create_asm_line(t_env *env)
{
	t_asm_line	*op;

	op = ft_lstadd_end(&env->head, env);
	if (check_label(env, op) == 0)
		return ;
	check_op(env, op);
	check_typecode(op);
	env->position_binary += op->line_len_bytes;
}

void		check_asm(t_env *env)
{
	while (get_next_line(env->fd, &env->line) > 0)
	{
		split_op_line(env);
		if (env->line_splitted != NULL)
			create_asm_line(env);
		clean_line_readed(env);
	}
	if (env->head == NULL)
		clean_exit(env, "Error: no operations in your code\n");
}
