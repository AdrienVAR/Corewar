/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:08:35 by cgiron            #+#    #+#             */
/*   Updated: 2018/12/14 14:11:21 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_power(int nb, int power)
{
	int m;

	if (power == 0)
		return (1);
	else if (power % 2 == 0)
	{
		m = ft_power(nb, power / 2);
		return (m * m);
	}
	return (nb * ft_power(nb, power - 1));
}
