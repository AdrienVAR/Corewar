/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:05:00 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/07 16:26:16 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Free the buffer if the memory has been allocated
** Print a pertinent error message
** Exit
*/

void	clean_exit(char *buffer, char *error_message)
{
	if (buffer)
		free(buffer);
	ft_putstr(error_message);
	exit(0);
}

/*
** Free each component of t_asm_line with malloc.
** Free the instruction.
** env->head points to the next instruction.
*/

void	free_asm_aline(t_asm_line *instruction, t_env *env)
{
	int i;

	i = - 1;
	while (instruction->line_splitted[++i])
		free(instruction->line_splitted[i]);
	free(instruction->line_splitted);
	if (instruction->line)
		free(instruction->line);
	// no {if (instruction->label) free (instruction->label)}, *label point on line_splitted[0]
	// no {if (instruction->name_op) free (instruction->name_op)}, *name_op point on line_splitted[1]
	env->head = instruction->next;
	free (instruction);
}

/*
** Free each component of t_env with malloc.
** Free the instruction's chained list.
** Free env.
*/
void	free_env(t_env *env)
{
	if (env->name)
		free(env->name);
	if (env->comment)
		free(env->comment);
	while (env->head)
		free_asm_aline(env->head, env);
	free (env);
}

/*
void	clean_exit(t_env *env, char *error_message)
{
	while (env->head)
	{
		free(env->head);
		env->head = env->head->next;
	}
	ft_putstr(error_message);
	exit(0);
}
*/