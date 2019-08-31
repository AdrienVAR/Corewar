/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:55 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/31 16:39:40 by cgiron           ###   ########.fr       */
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
# define ARENA_SIZE (MEM_SIZE + 32)/32
# define USAGE_STR "./corewar [-dump nbr_cycles] [[-n number] champion1.cor]\n"

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
	unsigned char		registry[REG_NUMBER][REG_SIZE];
	unsigned char		pc[REG_SIZE];
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
	int		nb;
	int		fd;
	char	*binary;
	int		code_size;
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
}				t_player;

/*
**		**********************************************
** **	Master struct containing arena and shared vals ** **
**		**********************************************
*/

typedef struct	s_master
{
	int			magic_number;
	int			nb_of_players;
	int			arena[ARENA_SIZE];
	t_player	*players[MAX_PLAYERS];
	void		*process;
}				t_master;

/*
**		**********
** **	PROTOTYPES ** **
**		**********
*/

void			init(t_master **mstr);
void			file_loading(t_master *mstr, int argc, char **argv);
void			exit_program(t_master *mstr);

#endif
