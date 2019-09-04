/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:55 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/04 10:25:01 by cgiron           ###   ########.fr       */
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

typedef	struct	s_vm_pcs_track
{
	int		last_live;
	int		wait;
}				t_vm_pcs_track;


typedef struct	s_process
{
	char				registry[REG_NUMBER][REG_SIZE];
	int					pc;
	int					carry;
	int					time_since_live;
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
