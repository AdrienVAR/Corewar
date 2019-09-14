/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2019/09/14 17:54:58 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/
#ifndef OP_H
# define OP_H

# define IND_SIZE				2
# define REG_SIZE				1
# define DIR_SIZE				4
# define MAX_SIZE				4

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

/*
**		****************
** 	**	ARENA PARAMETERS **
**		****************
*/

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

/*
**		**************************************
** 	**	ASSEMBLY MARKERS and LABEL LIMITATIONS **
**		**************************************
*/

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

/*
**		*****************
** 	**	SIGNATURE STRINGS **
**		*****************
*/

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

/*
**		***************
** 	**	GAME PARAMETERS **
**		***************
*/

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

/*
**		***************
** 	**	PARAMETER TYPE  **
**		***************
*/

typedef char	t_arg_type;

/*
** 	Types are define on 4 bits (1-0)label(1-0)ind(1-0)dir(1-0)reg
*/

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

/*
**		***********************************
** 	**	SIZE LIMITATIONS AND EXEC SIGNATURE  **
**		***********************************
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define AVAILABLE_OPERATIONS	17
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_op
{
	char	name[16];
	int		nb_params;
	int		params_type[MAX_ARGS_NUMBER];
	char	id;
	int		duration;
	char	description[64];
	int		type_needed;
	int		dir_size;
	int		idx_mod;
}					t_op;

typedef struct		s_type
{
	int		type;
	int		type_code;
	int		size;
}					t_type;

#endif
