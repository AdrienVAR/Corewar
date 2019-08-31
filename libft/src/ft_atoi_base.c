/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:35:27 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 12:55:53 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			ft_isvalid_base(char *str)
{
	int		i;
	int		vdouble;

	i = 0;
	while (str[i] != '\0')
	{
		vdouble = 1;
		while (str[i + vdouble] != '\0')
		{
			if (str[i + vdouble] == str[i])
			{
				return (0);
			}
			vdouble++;
		}
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

static int			part_of_base(char num, char *base, int *ind)
{
	int		i;
	int		part;

	part = 0;
	i = 0;
	while (base[i] != '\0')
	{
		if (num == base[i])
		{
			*ind = i;
			part = 1;
		}
		i++;
	}
	return (part);
}

static int			base_size(char *base)
{
	int		sz;

	sz = 0;
	while (base[sz] != '\0')
		sz++;
	return (sz);
}

int					ft_atoi_base(char *str, char *base)
{
	long	nb;
	int		sign;
	int		index;
	int		sz;
	int		i;

	sign = 1;
	i = 0;
	nb = 0;
	sz = base_size(base);
	if (ft_isvalid_base(base) != 1 || str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		sign = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (part_of_base(str[i], base, &index) == 1 && str[i] != '\0')
	{
		nb = sz * nb + index;
		i++;
	}
	if (str[i] == '\0' || str[i] == '+' || str[i] == '-')
		return (nb * sign);
	return (0);
}
