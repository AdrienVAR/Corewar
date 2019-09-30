/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:30:26 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/30 11:33:42 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft/ft_printf.h"

void	writing(char *file, t_env *env)
{
	int		fd;
	char	*tmp;
	char	*new_file;

	tmp = ft_strndup(file, ft_strlen(file) - 2);
	new_file = ft_strjoin(tmp, ".cor");
	free(tmp);
	if ((fd = open(new_file, O_CREAT | O_WRONLY | O_TRUNC, 0600)) == -1)
		clean_exit(-1, env, "Error: Opening/Creating new file has failed\n");
	writing_header(env, fd);
	writing_op(env, fd);
	if (close(fd) == -1)
		clean_exit(-1, env, "Error: Closing new file has failed\n");
	ft_printf("Success: Writing output program to %s\n", new_file);
	free(new_file);
}
