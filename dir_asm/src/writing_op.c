/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:47:20 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/10 17:20:35 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void    	writing_op(t_env *env, int fd)
{
	int			i;
	t_asm_line	*current;
	t_dir_cast	dir;
	t_ind_cast	ind;
	t_reg_cast	reg;

	current = env->head;
	while (current)
	{
		ft_putchar_fd(current->operation.id, fd);
		if (current->operation.type_needed)
			ft_putchar_fd(current->type_code, fd);
		i = -1;
		while (++i < current->operation.nb_params)
		{
			if (current->params_type[i].type == g_type[0].type)
			{
				reg.nb = current->param_value[i];
				ft_putchar_fd(reg.casted[0], fd);
			}
			else if (current->params_type[i].type == g_type[1].type)
			{
				if (current->operation.dir_size == 2)
				{
					ind.nb = current->param_value[i];
					ft_putchar_fd(ind.casted[1], fd);
					ft_putchar_fd(ind.casted[0], fd);
				}
				else
				{
					dir.nb = current->param_value[i];
					ft_putchar_fd(dir.casted[3], fd);
					ft_putchar_fd(dir.casted[2], fd);
					ft_putchar_fd(dir.casted[1], fd);
					ft_putchar_fd(dir.casted[0], fd);
				}
			}
			else
			{
				ind.nb = current->param_value[i];
				ft_putchar_fd(ind.casted[1], fd);
				ft_putchar_fd(ind.casted[0], fd);
			}
		}
		current = current->next;
	}
}
