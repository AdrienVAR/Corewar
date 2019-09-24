/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:59:45 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/24 13:01:06 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int			is_integer(char *line);
void		*memrevcpy(void *dst, const void *src, int n);
int			rgb(unsigned char r, unsigned char g, unsigned char b);
int			multi_turn_selector(int mult, int plusmin);

#endif
