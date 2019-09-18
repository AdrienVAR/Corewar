/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:23:08 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/03 15:23:39 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fetch_str(t_master *mstr, wchar_t **strl, char **str)
{
	int size;

	size = mstr->options[7];
	*strl = NULL;
	*str = NULL;
	if (size == 2 || mstr->options[8] == TYPE_CAP_S)
		*strl = (int *)va_arg(mstr->arg, int *);
	else
		*str = (char *)va_arg(mstr->arg, char *);
	mstr->fringe[2] = !(*strl) && !(*str) ? 1 : 0;
}
