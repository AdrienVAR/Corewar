/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:50:17 by advardon          #+#    #+#             */
/*   Updated: 2019/09/09 11:33:07 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"



void    ft_put_t_asm_lines(t_env *env)
{
    int i;
    
    i = 0;
    while(env->head)
    {
        ft_putstr("--------------------\n");
        i = 0;
        ft_putstr("line_splitted\n");
        while (env->head->line_splitted && env->head->line_splitted[i])
        {
            ft_putstr(env->head->line_splitted[i++]);
            ft_putstr("\n");
        }
        ft_putstr("\n");
        ft_putstr("line\n");
        ft_putstr(env->head->line);
        ft_putstr("\n");
        ft_putstr("line_pos_bytes\n");
        ft_putnbr(env->head->line_pos_bytes);
        ft_putstr("\n");
        ft_putstr("line_len_bytes\n");
        ft_putnbr(env->head->line_len_bytes);
        ft_putstr("\n");
        ft_putstr("label\n");
        ft_putstr(env->head->label);
        ft_putstr("\n");
        ft_putstr("name_operations\n");
        ft_putstr(env->head->name_operations);
        ft_putstr("\n");
        ft_putstr("type_code\n");
        ft_putchar(env->head->type_code);
        i = 0;
        ft_putstr("params_value\n");
        while (i < 4)
        {
            ft_putnbr(env->head->param_value[i++]);
            ft_putstr("\n");
        }
        env->head = env->head->next;
    }
}

/*
** Create a new struct and add it at end of the list.
*/

t_asm_line	*ft_lstadd_end(t_asm_line **lst)
{
	t_asm_line	*lstnew;
	t_asm_line	*lnext;
    t_asm_line  *lstart;

    lstart = *lst;
	if (!(lstnew = (t_asm_line *)ft_memalloc(sizeof(t_asm_line))))
		return (NULL);
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

void    create_asm_line(t_env *env, char *line)
{
    t_asm_line	*instruction;
    
	
    instruction = ft_lstadd_end(&env->head);
	if (!(instruction->line_splitted = split_line(line, 1)))
		return ;
    if (instruction->line_splitted[0] == NULL) //check empty lines DO BEFORE CREATE MAILLON
        return;
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
    env->position_binary += instruction->line_len_bytes;
    ft_putstr(instruction->name_operations);
    //ft_put_t_asm_lines(env);
}