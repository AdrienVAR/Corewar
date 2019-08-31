/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:35:51 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/09 14:06:24 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ns;

	ns = n;
	if (ns < 0)
	{
		ns = -ns;
		ft_putchar_fd('-', fd);
	}
	if (ns < 10)
	{
		ft_putchar_fd('0' + ns, fd);
		return ;
	}
	ft_putnbr_fd(ns / 10, fd);
	ft_putnbr_fd(ns % 10, fd);
}
