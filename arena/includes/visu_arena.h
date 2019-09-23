/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_arena.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:50:53 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/23 18:47:16 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_ARENA_H
# define VISU_ARENA_H

# define YRES 1080
# define XRES 1920
# define TOP_Y 100
# define BOTTOM_Y 100
# define LEFT_X 50

# define SPACE 49
# define ESCAPE 53

# define MLX_PTR 0
# define WIN_PTR 1
# define I_PTR 2
# define I_ADR 3

# define COLOR_BASIC 0xFFFFFF
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
	U_ONE_TURN
}					t_update;

typedef struct	s_visu
{
	void		*mem_ptr[4];
	t_update	update;
}				t_visu;

void			clear_window(t_visu *visu);
int				key_simple_press(int key, t_visu *visu);
int				key_loop(int key, t_visu *visu);
void			reset_screen(void **mem_ptr);

#endif
