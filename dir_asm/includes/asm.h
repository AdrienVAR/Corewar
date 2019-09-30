/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:04:14 by gdrai             #+#    #+#             */
/*   Updated: 2019/09/30 15:29:09 by gdrai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# include "op.h"

extern t_op g_op_tab[AVAILABLE_OPERATIONS];
extern t_type g_type[4];

typedef struct			s_asm_line
{
	int					line_pos_bytes;
	int					line_len_bytes;
	char				*label;
	t_op				operation;
	t_type				params_type[4];
	char				*param_label[4];
	char				type_code;
	int					param_value[4];
	struct s_asm_line	*next;
}						t_asm_line;

typedef struct			s_env
{
	char				*line;
	char				**line_splitted;
	char				*name;
	char				*comment;
	int					position_binary;
	int					fd;
	int					count;
	int					quote;
	int					white_space;
	int					first_w;
	int					sep;
	int					num_line;
	char				*filename;
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

/*
** check_extension.c
*/
int						check_extention(char *file);

/*
** parsing.c
*/
void					parsing(char *file, t_env *env);

/*
** check_op.c
*/
void					check_op(t_env *env, t_asm_line *op);

/*
** check_header.c
*/
void					check_header(t_env *env);

/*
** check_asm.c
*/
void					check_asm(t_env *env);

/*
** check_label.c
*/
int						check_label(t_env *env, t_asm_line *op);
void					check_syntax_label(t_env *env, char *label);

/*
** clean_exit.c
*/
void					clean_exit(int col, t_env *env, char *error_message);
void					clean_line_readed(t_env *env);

/*
** split_op_line.c
*/
void					split_op_line(t_env *env);

/*
** split_header_line.c
*/
void					split_header_line(t_env *env);

/*
** fill_label.c
*/
void					fill_label(t_env *env);

/*
** writing.c
*/
void					writing(char *file, t_env *env);

/*
** writing_header.c
*/
void					writing_header(t_env *env, int fd);

/*
** writing_op.c
*/
void					writing_op(t_env *env, int fd);

/*
** check_digits.c
*/
void					check_digits(t_env *env, t_asm_line *op,
						int param, char *str);

/*
** check_valid_type.c
*/
void					check_valid_type(t_asm_line *op, int param, t_env *env);

/*
** check_typecode.c
*/
void					check_typecode(t_asm_line *op);

#endif
