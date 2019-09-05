/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <advardon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:04:14 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/05 15:12:13 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# include "op.h"

extern t_op g_op_tab[AVAILABLE_OPERATIONS];
extern t_type	g_type[4];

typedef struct	s_asm_line
{
	char				**line_splitted;
	char				*line; // line from GNL
    int                 line_pos_bytes; // position line en debut de ligne
    int                 line_len_bytes; // lenght of the line
	char                *label;
	char				*name_operations;
	t_op                operation; // line op.c
	t_type              params_type[4];
	char				type_code; // donne les types DIR/IND/REG des parametres
	int					param_value[4]; // pas mettre value si on a un type label
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
char    **split_line(char *line, int option);

#endif
