/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_arena.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:50:53 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/25 18:21:33 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_ARENA_H
# define VISU_ARENA_H

# define YRES 1080
# define XRES 1920

# define TOP_Y 150
# define STD_BUF 25
# define STD_NEW_LINE 22
# define MAX_VISU_NAME_LEN 16
# define BOTTOM_Y STD_BUF
# define LEFT_X STD_BUF
# define RIGHT_X STD_BUF

# define WINNER_Y 200


# define RIGHT_BAR_SIZE 500
# define RIGHT_BAR_X (XRES - RIGHT_X - RIGHT_BAR_SIZE)
# define ARENA_X (RIGHT_BAR_X - LEFT_X)
# define ARENA_Y (YRES - (TOP_Y + BOTTOM_Y))

# define BYTE_X (ARENA_X / 64)
# define BYTE_Y (ARENA_Y / (MEM_SIZE / 64))

# define SPACE 49
# define ESCAPE 53
# define TOUCH_P 35
# define TOUCH_UP 126
# define TOUCH_DOWN 125
# define TOUCH_M 46
# define TOUCH_A 0

# define NO_CURSOR 1
# define CURSOR_PRESENT 2
# define CURSOR_ACTIVE 3

# define I_PTR 0
# define I_ADR 1
# define MLX_PTR 2
# define WIN_PTR 3


# define COLOR_BACKGROUND 0x1F1F1F
# define COLOR_BASIC 0xEFEFFF
# define COLOR_LESS_BASIC 0xFF6F6F
# define COLOR_CURSOR 0x8F8F8F
# define COLOR_CURSOR_ACT 0xAFAFAF
# define VISU_DIM 80
# define P1_COL 0x00FFFF
# define P2_COL 0x00FF00
# define P3_COL 0xFF0000
# define P4_COL 0xFF00FF

typedef enum		e_update
{
	U_IDLE,
	U_END,
	U_STOP,
	U_ONE_TURN,
	U_TILL_THE_END,
	U_REFRESH,
	U_MULTI_TURN,
	U_TILL_SOMETHING_HAPPEN,
}					t_update;

typedef struct	s_visu
{
	void		*mem_ptr[4];
	void		*header;
	int			header_size[2];
	t_update	update;
	int			multi;
	int			ended;
}				t_visu;

void			clear_window(t_visu *visu);
int				key_simple_press(int key, t_visu *visu);
int				key_loop(int key, t_visu *visu);
void			flush_image(t_visu *visu);
void			draw_pixel(t_visu *visu, int x, int y, int color);
int				player_color(int player);
void			draw_square_image(t_visu *visu, int pos[2],
					int dim[2], int color);

#endif
