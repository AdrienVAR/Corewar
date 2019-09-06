/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:05:00 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/06 16:19:00 by advardon         ###   ########.fr       */
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