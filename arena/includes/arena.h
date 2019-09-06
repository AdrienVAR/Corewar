/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:55 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/06 16:15:28 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "op.h"
# include <stdio.h> //to remove

extern t_op	g_op_tab[AVAILABLE_OPERATIONS];
extern t_type	g_type[4];

/*
**		*******
** **	DEFINES	** **
**		*******
*/

/*
** **	BOOLEAN
*/

# define YES 1
# define NO 2

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
**		************************
** **	UNION FOR BINARY CASTING ** **
**		************************
*/

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

typedef unsigned char	t_uchar;



/*
**		*********************************
** **	Process List we can cycle through ** **
**		*********************************
*/

typedef	struct	s_command
{
	t_op		op;
	char		param[MAX_ARGS_NUMBER][MAX_SIZE];
	t_reg_cast	reg_val[MAX_ARGS_NUMBER];
	t_ind_cast	ind_val[MAX_ARGS_NUMBER];
	t_type		types[MAX_ARGS_NUMBER];
}				t_command;


typedef	struct	s_vm_pcs_track
{
	int			last_live;
	int			alive;
	int			wait;
	t_command	command;
}				t_vm_pcs_track;


typedef struct	s_process
{
	char				registry[REG_NUMBER][DIR_SIZE];
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
	int				last_player_live;
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



char			arena_val(char *arena, int ind);
t_type			type_val(int type_code);

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

int				command_get_info(t_process *cur_process, t_uchar op_code);
void			command_get_types(t_process *cur_process, t_uchar type_code);
void			command_get_param(t_process *cur_process, char *arena);
int				command_valid_types(t_command command);
int				command_extract_register(t_command *command);
void			command_extract_indirect(t_command *command);
void			ex_command_live(t_process *process, char *arena);
void			ex_command_ld(t_process *process, char *arena);

void			cursor_next_op(t_process *process);

#endif
