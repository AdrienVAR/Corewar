/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:30:26 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/11 11:18:45 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	writing(char *file, t_env *env)
{
	int		fd;
	char	*tmp;
	char	*new_file;

	new_file = ft_strndup(file, ft_strlen(file) - 2);
	tmp = ft_strjoin("./", new_file);
	free(new_file);
	new_file = ft_strjoin(tmp, ".cor");
	free(tmp);
	if ((fd = open(new_file, O_CREAT | O_WRONLY | O_TRUNC, 0600)) == -1)
		clean_exit(env, "Error: Opening/Creating new file has failed\n");
	free(new_file);
	writing_header(env, fd);
	writing_op(env, fd);
	if (close(fd) == -1)
		clean_exit(env, "Error: Closing new file has failed\n");
}
