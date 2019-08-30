/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:05:00 by gdrai             #+#    #+#             */
/*   Updated: 2019/08/30 14:08:13 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

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
