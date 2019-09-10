/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:04:14 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/10 15:42:06 by gdrai            ###   ########.fr       */
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
    int                 line_pos_bytes; // position line en debut de ligne
    int                 line_len_bytes; // lenght of the line
	char                *label;
	t_op                operation; // line op.c
	t_type              params_type[4];
	char				*param_label[4];
	char				type_code; // donne les types DIR/IND/REG des parametres
	int					param_value[4]; // pas mettre value si on a un type label
	struct s_asm_line        *next;
}				t_asm_line;


typedef struct 			s_env
{
	char				**line_splitted;
	char				*name;
	char				*comment;
	char				*line; // line being readed by GNL 
	int					position_binary;
	t_asm_line			*head;
}						t_env;

typedef union			u_int_cast
{
	int					nb : 32;
	unsigned char		casted[4];
}						t_int_cast;

typedef union			u_dir_cast
{
	int					nb : DIR_SIZE * 8;
	unsigned char		casted[DIR_SIZE];
}						t_dir_cast;

typedef union			u_ind_cast
{
	int					nb : IND_SIZE * 8;
	unsigned char		casted[IND_SIZE];
}						t_ind_cast;

typedef union			u_reg_cast
{
	int					nb : REG_SIZE * 8;
	unsigned char		casted[REG_SIZE];
}						t_reg_cast;

void    lenline_opcode_typecode(t_asm_line *instruction);

int			check_extention(char *file);
void		parsing(char *file, t_env *env);
void		check_header(t_env *env, int fd);
void		def_type_code(t_asm_line *instruction);
/*
** check_name_op.c
*/
void		check_name_op(t_env *env, t_asm_line *instruction);

/*
** check_asm.c
*/
void		check_asm(t_env *env, int fd);

/*
** check_label.c
*/
void		check_label(t_env *env, t_asm_line *instruction);

/*
** clean_exit.c
*/
void		clean_exit(t_env *env, char *error_message);
void		clean_line_readed(t_env *env);

/*
** split_op_line.c
*/
char		**split_op_line(t_env *env, char *line);

/*
** split_header_line.c
*/
char		**split_header_line(t_env *env, char *line);

/*
** fill_label.c
*/
void		fill_label(t_env *env);

/*
** writing.c
*/
void		writing(char *file, t_env *env);

#endif
