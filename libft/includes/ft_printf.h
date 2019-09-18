/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 07:50:58 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 16:01:24 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./ftoa.h"
# include "./libft.h"
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>
# include <stdarg.h>

# define BUFFER 512
# define CONVERSION "%idspuoxXUcCSDOfFeEgG~bBrkn"
# define OPTION_LST "-+#0 .123456789hlLjz*"
# define SIZE_LST "hlLjz"
# define FRINGE_SIZE 3
# define OPTIONS_SIZE 9
# define DICO_CONV_SIZE 27
# define PRE_PTR 0
# define PRE_OC 1
# define PRE_CAP_HEX 2
# define PRE_HEX 3
# define PRE_CAP_BIN 6
# define PRE_BIN 5
# define PRE_CAP_O 4
# define PRE_RESET 100
# define TYPE_U 6
# define TYPE_OC 7
# define TYPE_HEX 8
# define TYPE_CAP_HEX 9
# define TYPE_CAP_U 10
# define TYPE_CAP_C 12
# define TYPE_CAP_S 13
# define TYPE_CAP_D 14
# define TYPE_CAP_O 15
# define TYPE_CAP_BIN 20
# define TYPE_BIN 19
# define DEFAULT_PREC 6

/*
** fringe [0] 0 si nul 1 si non nul maintien lors des recast int;
** fringe [1] 0 si nul 1 si non nul maintien lors des recast unsigned;
** fringe [2] 1 si str && strl sont nuls 0 sinon;
*/

typedef struct	s_printf
{
	char		flt_str[MAX_STR_SZ];
	char		*shuttle;
	va_list		arg;
	t_list		*buffer;
	int			options[OPTIONS_SIZE];
	int			size;
	int			fringe[FRINGE_SIZE];
	int			prefix[2];
	int			error;
	int			returnval;
}				t_printf;

int				ft_printf(const char *restrict format, ...);
int				ft_sprintf(char *str, const char *restrict format, ...);
int				ft_asprintf(char **str, const char *restrict format, ...);
int				ft_dprintf(int fd, const char *restrict format, ...);
void			ft_buffer_grow(t_printf *mstr);
void			ft_update_buffer(t_printf *mstr, char c);
void			ft_buffer_del(t_list **buffer);
void			ft_list_print(t_list *buffer, t_printf *mstr);
void			ft_list_sprint(char *str, t_list *buffer, t_printf *mstr);
void			ft_list_asprint(char **str, t_list *buffer, t_printf *mstr);
void			ft_list_dprint(int fd, t_list *buffer, t_printf *mstr);
void			ft_flag_mngmt(t_printf *mstr);
char			*ft_flag_option_check(char *navette, t_printf *mstr);
void			ft_init_printf(t_printf *mstr, const char *restrict format);
intmax_t		ft_fetch_int(t_printf *mstr);
uintmax_t		ft_fetch_ptr(t_printf *mstr);
uintmax_t		ft_fetch_time(t_printf *mstr);
void			ft_fetch_str(t_printf *mstr, wchar_t **strl, char **str);
void			ft_fetch_char(t_printf *mstr, wint_t *chrl, char *chr);
void			ft_fetch_flt(t_printf *mstr, double *dbl, long double *ldbl);
uintmax_t		ft_fetch_u_int(t_printf *mstr);
intmax_t		*ft_fetch_int_adr(t_printf *mstr);
void			ft_conv_int(t_printf *mstr);
void			ft_conv_percent(t_printf *mstr);
void			ft_conv_str(t_printf *mstr);
void			ft_conv_np_str(t_printf *mstr);
void			ft_conv_ptr(t_printf *mstr);
void			ft_conv_char(t_printf *mstr);
void			ft_conv_u_int(t_printf *mstr);
void			ft_conv_flt(t_printf *mstr);
void			ft_conv_flt_e(t_printf *mstr);
void			ft_conv_flt_g(t_printf *mstr);
void			ft_conv_time(t_printf *mstr);
void			ft_conv_color(t_printf *mstr);
void			ft_conv_n(t_printf *mstr);
int				ft_int_size_base(intmax_t nb, int base_sz);
int				ft_u_int_size_base(intmax_t nb, int base_sz);
void			ft_buffer_digits_base(t_printf *mstr,
		uintmax_t nb, char *base);
void			ft_prefixes(t_printf *mstr, int prefix);
int				ft_unichar_length(wchar_t uni);
void			ft_add_uni_buffer(t_printf *mstr, wchar_t uni);
void			ft_standard_padding(t_printf *mstr, char c);
int				ft_prec_zero_pref(int type);
void			ft_str_to_buffer(t_printf *mstr, char *str);

#endif
