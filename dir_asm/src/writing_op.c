/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:47:20 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/30 14:16:30 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	writing_direct_op(t_asm_line *current, int fd, int i)
{
	int			size;
	t_dir_cast	dir;
	t_ind_cast	ind;

	if (current->operation.dir_size == IND_SIZE)
	{
		size = IND_SIZE - 1;
		ind.nb = current->param_value[i];
		while (size >= 0)
			ft_putchar_fd(ind.casted[size--], fd);
	}
	else
	{
		size = DIR_SIZE - 1;
		dir.nb = current->param_value[i];
		while (size >= 0)
			ft_putchar_fd(dir.casted[size--], fd);
	}
}

void	writing_op_bis(t_asm_line *current, int fd, int i)
{
	int			size;
	t_ind_cast	ind;
	t_reg_cast	reg;

	if (current->params_type[i].type == REG_CODE)
	{
		size = REG_SIZE - 1;
		reg.nb = current->param_value[i];
		while (size >= 0)
			ft_putchar_fd(reg.casted[size--], fd);
	}
	else if (current->params_type[i].type == DIR_CODE)
		writing_direct_op(current, fd, i);
	else
	{
		size = IND_SIZE - 1;
		ind.nb = current->param_value[i];
		while (size >= 0)
			ft_putchar_fd(ind.casted[size--], fd);
	}
}

void	writing_op(t_env *env, int fd)
{
	int			i;
	t_asm_line	*current;

	current = env->head;
	while (current)
	{
		if (current->line_len_bytes != 0)
		{
			ft_putchar_fd(current->operation.id, fd);
			if (current->operation.type_needed)
				ft_putchar_fd(current->type_code, fd);
			i = -1;
			while (++i < current->operation.nb_params)
				writing_op_bis(current, fd, i);
		}
		current = current->next;
	}
}
