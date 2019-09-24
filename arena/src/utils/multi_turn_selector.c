/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_turn_selector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:51:33 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/24 17:12:52 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			multi_turn_selector(int mult, int plusmin)
{
	if (mult == 1)
		return (plusmin ? 2 : 1);
	if (mult == 2)
		return (plusmin ? 5 : 1);
	if (mult == 5)
		return (plusmin ? 6 : 2);
	if (mult == 6)
		return (plusmin ? 10 : 5);
	if (mult == 10)
		return (plusmin ? 25 : 6);
	if (mult == 25)
		return (plusmin ? 50 : 10);
	if (mult == 50)
		return (plusmin ? 100 : 25);
	if (mult == 100)
		return (plusmin ? 100 : 50);
	return (1);
}
