/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:04:14 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/04 16:04:40 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
#  include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# include "op.h"

typedef struct	s_asm_line
{
	char				**line_splitted;
	char				*line; // line from GNL
    int                 line_pos_bytes; // position line en debut de ligne
    int                 line_len_bytes; // lenght of the line
	char                *label;
	t_op                *operation;
	int                 nb_params;
	char                params_type[4];
	struct s_asm_line        *next;
}				t_asm_line;

typedef struct 			s_env
{
	char				*name;
	char				*comment;
}						t_env;

void	clean_exit(char *buffer, char *error_message);
int		check_extention(char *file);
void	parsing(char *file, t_env *env);
void    checker_name(char *line);
t_asm_line	*ft_lstadd_end(t_asm_line *lst);

#endif
