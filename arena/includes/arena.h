/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:55 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/04 19:06:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "op.h"

extern t_op g_op_tab[17];

/*
**		*******
** **	DEFINES	** **
**		*******
*/

/*
** **	ARENA
*/

# define USAGE_STR "./corewar [-dump nbr_cycles] [[-n number] champion1.cor]\n"
# define DUMP_SIZE 64 // change back to 32

/*
** **	OPTION
*/
# define OPT_N "-n"
# define OPT_DUMP "-dump"

/*
**		*********************************
** **	Process List we can cycle through ** **
**		*********************************
*/

typedef	struct	s_command
{
	t_op		op;
	char		param[MAX_ARGS_NUMBER][MAX_ARGS_NUMBER];
	int			types[MAX_ARGS_NUMBER];
	int			types_size[MAX_ARGS_NUMBER];
}				t_command;


typedef	struct	s_vm_pcs_track
{
	int			last_live;
	int			wait;
	t_command	command;
}				t_vm_pcs_track;


typedef struct	s_process
{
	char				registry[REG_NUMBER][REG_SIZE];
	int					pc;
	int					carry;
	t_vm_pcs_track		vm;
	struct s_process	*next;
}				t_process;

/*
**		************
** **	Players data ** **
**		************
*/

typedef struct	s_player
{
	int				magic;
	int				nb;
	int				fd;
	int				cursor_initial_pos;
	char			*binary;
	int				code_size;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	char			exec[CHAMP_MAX_SIZE + 1];
}				t_player;

/*
**		**********************************************
** **	Master struct containing arena and shared vals ** **
**		**********************************************
*/

typedef struct	s_master
{
	int				magic_number;
	int				nb_of_players;
	char			arena[MEM_SIZE];
	t_player		*players[MAX_PLAYERS];
	t_process		*process;
	int				foamy_bat_cycle;
	int				cur_cycle;
}				t_master;

/*
**		**********
** **	PROTOTYPES ** **
**		**********
*/

void			init(t_master **mstr);
void			file_loading(t_master *mstr, int argc, char **argv);
void			deassembler(t_master *mstr);
void			file_closing(t_master *mstr);

/*
**		************************
** **	UNION FOR BINARY CASTING ** **
**		************************
*/

typedef union			u_int_char_cast
{
	int					nb : 32;
	unsigned char		casted[4];
}						t_int_char_cast;

typedef union			u_int_dir_cast
{
	int					nb : T_DIR * 8;
	unsigned char		casted[T_IND];
}						t_int_dir_cast;

typedef union			u_int_reg_cast
{
	int					nb : T_REG * 8;
	unsigned char		casted[T_REG];
}						t_int_reg_cast;

typedef unsigned char	uchar;

char	arena_val(char *arena, int ind);

/*
** **	BINARY_READ
*/

int				binary_read_integer(int fd, t_master *mstr);
void			binary_read_string(int fd, char *str, int sz, t_master *mstr);
void			binary_read_null(int fd, t_master *mstr);
void			arena_populate(t_master *mstr);
void			memory_dump(t_master *mstr);
void			player_give_process(t_master *mstr);
void			war(t_master *mstr);
t_op			operation_get_info(char op_code);
void			exit_program(t_master *mstr);

#endif
