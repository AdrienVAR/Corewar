/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_dimmer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:14:56 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 09:47:46 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				color_dimmer(int color, int dim)
{
	int dimmed;

	dimmed = (color >> 16 & 0xff) * dim / 100;
	dimmed *= 256;
	dimmed += ((color >> 8) & 0xff) * dim / 100;
	dimmed *= 256;
	dimmed += (color & 0xff) * dim / 100;
	return (dimmed);
}
