/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace_len.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:19:03 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/13 13:33:57 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				ft_split_whitespace_len(char const *s)
{
	size_t		wl;

	if (!s || !*s)
		return (0);
	while (!(wl = 0) && ((*s >= 8 && *s <= 13) || *s == 32))
		s++;
	if (!*s)
		return (0);
	while (s[wl] && ((s[wl] < 8 || s[wl] > 13) && s[wl] != 32))
		wl++;
	return (1 + ft_split_whitespace_len(s + wl));
}
