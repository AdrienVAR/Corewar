/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:55 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/02 16:20:53 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "op.h"

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

typedef struct	s_process
{
	char				registry[REG_NUMBER][REG_SIZE];
	char				pc[REG_SIZE];
	int					carry;
	int					alive;
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
	void			*process;
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
** **	BINARY_READ
*/
int				binary_read_integer(int fd, t_master *mstr);
void			binary_read_string(int fd, char *str, int sz, t_master *mstr);
void			binary_read_null(int fd, t_master *mstr);
void			arena_populate(t_master *mstr);
void			memory_dump(t_master *mstr);
void			exit_program(t_master *mstr);

#endif
