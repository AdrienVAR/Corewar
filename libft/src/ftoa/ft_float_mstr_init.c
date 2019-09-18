/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_mstr_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:55:27 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/21 11:55:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa.h"

void	ft_float_mflt_init(t_flt_mstr *mflt)
{
	int i;

	i = -1;
	while (++i < MAX_NB_SZ)
		(mflt->nb)[i] = 0;
	i = -1;
	while (++i < FLT_PREC + 1)
		(mflt->mantisa)[i] = 0;
	i = -1;
	while (++i < CAST_SZ)
		(mflt->cast)[i] = 0;
	mflt->exp = 0;
	mflt->sign = 0;
	mflt->coma_pos = 1;
	mflt->nb_len = 0;
}
