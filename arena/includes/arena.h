/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:59:55 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/27 15:09:01 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "op.h"
# include "visu_arena.h"

/*
**		*******************************
** **	INCLUDE OP-TABLE AND TYPE-TABLE	** **
**		*******************************
*/

extern t_op				g_op_tab[AVAILABLE_OPERATIONS];
extern t_type			g_type[4];

/*
**		*******
** **	DEFINES	** **
**		*******
*/

/*
** **	BOOLEAN
*/

# define YES 1
# define NO 0

/*
** **	ARENA
*/

# define USAGE_STR "./corewar [-dump nbr_cycles] [[-n number] champion1.cor]\n"
# define DUMP_SIZE 32

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

typedef	struct			s_command
{
	t_op				op;
	char				param[MAX_ARGS_NUMBER][MAX_SIZE];
	t_dir_cast			param_conv[MAX_ARGS_NUMBER];
	t_dir_cast			param_ext_conv[MAX_ARGS_NUMBER];
	t_type				types[MAX_ARGS_NUMBER];
}						t_command;

typedef	struct			s_vm_pcs_track
{
	int					last_live;
	int					alive;
	int					wait;
	int					process_nb;
	int					player;
	t_command			command;
}						t_vm_pcs_track;

typedef struct			s_process
{
	char				registry[REG_NUMBER][DIR_SIZE];
	int					pc;
	int					carry;
	t_vm_pcs_track		vm;
	struct s_process	*next;
}						t_process;

/*
**		************
** **	Players data ** **
**		************
*/

# define BUFFER_AFF_SIZE 36

typedef struct			s_player
{
	int					magic;
	int					nb;
	int					fd;
	int					cursor_initial_pos;
	char				*binary_name;
	int					code_size;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	char				exec[CHAMP_MAX_SIZE + 1];
	int					life_signals;
	char				buffer_aff[BUFFER_AFF_SIZE + 1];
	char				buffer_aff_pos;
}						t_player;

/*
**		******************
** **	Options management ** **
**		******************
*/

# define VERBOSE_LIFE 1
# define VERBOSE_DEATH 2
# define VERBOSE_BORN 4
# define VERBOSE_OPER 8
# define VERBOSE_CURS 16
# define VERBOSE_CYCL 32

# define OPT_N "-n"
# define OPT_A "-a"
# define OPT_DUMP "-dump"
# define OPT_VISU "-visu"
# define OPT_VERB "-v"
# define COR_EXT ".cor"
# define N_DUMP 1
# define END_DUMP 2

typedef struct			s_opt
{
	int					verbose;
	char				visu;
	char				aff;
	int					dump;
	int					end_dump;
	int					player[MAX_PLAYERS][2];
	int					nb_players;
}						t_opt;

/*
**		**********************************************
** **	Master struct containing arena and shared vals ** **
**		**********************************************
*/

/*
** **	ARENA STRUCT
*/

typedef struct			s_arena
{
	t_uchar		value;
	int			player;
	char		cursor;
}						t_arena;

/*
** **	MASTER STRUCT
*/

typedef struct			s_master
{
	int					magic_number;
	int					nb_of_players;
	int					last_player_live;
	int					live_signal;
	int					something_happened;
	int					check;
	int					active_processes;
	int					total_processes;
	t_arena				arena[MEM_SIZE];
	t_player			*players[MAX_PLAYERS];
	t_player			*sorted_player[MAX_PLAYERS];
	t_process			*process;
	t_opt				options;
	int					foamy_bat_cycle;
	int					ctd;
	int					cur_cycle;
	t_visu				*visu;
	int					someone_lived;
}						t_master;

/*
**		**********
** **	PROTOTYPES ** **
**		**********
*/

void					init(t_master **mstr, t_opt *options);
void					deassembler(t_master *mstr, t_player *player);
void					file_closing(t_player *player);
void					file_loading(t_master *mstr, t_player *player,
							char *filename);
t_uchar					arena_val_get(t_arena *arena, int ind);
void					arena_val_set(t_arena *arena, char c, int ind,
							int player);
t_type					type_val(int type_code);

/*
** **	BINARY_READ
*/

int						binary_read_integer(int fd, t_master *mstr);
void					binary_read_string(int fd, char *str, int sz,
							t_master *mstr);
void					binary_read_null(int fd, t_master *mstr);
void					arena_populate(t_master *mstr);
void					memory_dump(t_master *mstr);
void					player_give_process(t_master *mstr);
void					war(t_master *mstr);
void					run_cycle(t_master *mstr);
int						process_killing(t_master *mstr, t_process **process);
t_op					operation_get_info(char op_code);
void					exit_program(t_master *mstr);
void					free_everything(t_master *mstr);
void					print_winner(t_player *player, int someone_lived);
int						option_get(t_opt *opt, int argc, char **argv);

void					command_get_info(t_process *cur_process,
							int pc, t_arena *arena);
void					command_get_types(t_process *cur_process,
							int pc, t_arena *arena);
void					command_get_param(t_process *cur_process,
							t_arena *arena);
int						command_convert_param(t_process *process,
							t_arena *arena);
int						command_valid_types(t_command command);
t_dir_cast				command_extract_direct_value(t_arena *arena, int dec,
							int pos);
void					ex_command_live(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_ld(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_st(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_add(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_sub(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_and(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_or(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_xor(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_zjmp(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_ldi(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_sti(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_fork(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_lld(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_lldi(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_lfork(t_master *mstr,
							t_process *process, t_arena *arena);
void					ex_command_aff(t_master *mstr,
							t_process *process, t_arena *arena);

void					cursor_next_op(t_process *process, int verbose);

void					visu_corewar(t_master *mstr);
void					exit_visu(t_master *mstr);
void					refresh_arena(t_master *mstr, t_visu *visu);
void					visu_play_one_turn(t_master *mstr, t_visu *visu);
void					visu_play_multi_turn(t_master *mstr, t_visu *visu);
void					refresh(t_master *mstr, t_visu *visu);
void					draw_cursors_image(t_master *mstr, t_visu *visu);
void					clean_image_background(t_visu *visu);
void					visu_play_till_action(t_master *mstr, t_visu *visu);
void					refresh_sidebar(t_master *mstr, t_visu *visu);
void					refresh_sidebar_player(t_master *mstr, t_visu *visu);

#endif
