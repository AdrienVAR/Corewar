/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:54:56 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/19 17:07:22 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int				is_integer(char *line)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while ((line[i] >= 8 && line[i] <= 13) || line[i] == 32)
		++i;
	if (line[i] == '+' || line[i] == '-')
		++i;
	while (line[i] == '0')
		++i;
	while (ft_isdigit(line[i + len]))
		len++;
	if ((len && !ft_atoi(line)) || i + len != (int)ft_strlen(line))
		return (0);
	return (1);
}
