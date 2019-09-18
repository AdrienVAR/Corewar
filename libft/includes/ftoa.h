/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:05:24 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/18 09:18:09 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTOA_H
# define FTOA_H
# include <inttypes.h>
# define MAX_DIGITS		16400
# define MAX_STR_SZ		MAX_DIGITS + 3
# define FLT_PREC		64
# define CAST_SZ		66
# define NEG_POW_2_SZ	80
# define LDBL_SZ		(1+15+64)
# define REDUCE_WRK_BASE	8
# define REDUCE_PREC	(FLT_PREC/REDUCE_WRK_BASE)
# define MAX_NB_SZ 		MAX_DIGITS / REDUCE_WRK_BASE
# define ZERO_EXP_LDBL	16383
# define ZERO_EXP_DBL	1023
# define STEP_EXP		30

typedef long long int	t_lli;

typedef union			u_ldbl_cast
{
	long double			f;
	struct {
		unsigned long	mantissa : 64;
		unsigned long	exp : 15;
		int				sign : 1;
	}					parts;
}						t_ldbl_cast;

typedef union			u_dbl_cast
{
	double				f;
	struct {
		unsigned long	mantissa : 52;
		unsigned long	exp : 11;
		int				sign : 1;
	}					parts;
}						t_dbl_cast;

typedef struct			s_flt_mstr
{
	int					mantisa[FLT_PREC + 1];
	int					cast[FLT_PREC + 2];
	int					exp;
	int					z_exp;
	int					e_exp;
	int					sign;
	int					nb[MAX_NB_SZ];
	int					coma_pos;
	int					nb_len;
	char				*str_out;
	int					precision;
	int					science;
	t_ldbl_cast			u_ldbl;
	t_dbl_cast			u_dbl;
}						t_flt_mstr;

void					ft_ftoa_ldbl(char *str_out, long double flt,
		int precision, int science);
void					ft_ftoa_dbl(char *str_out, double flt, int precision,
		int science);
int						ft_div_tab(int **num, int divider, int len, t_lli base);
int						ft_add_tab(int **num, int *add, int len, t_lli base);
int						ft_mult_tab(int **num, int multiplier,
		int len, t_lli base);
void					ft_float_bin_ldbl_extract(t_flt_mstr *mflt);
void					ft_float_bin_dbl_extract(t_flt_mstr *mflt);
void					ft_float_get_mantissa(t_flt_mstr *mflt, t_lli base);
void					ft_float_apply_exp(t_flt_mstr *mflt, t_lli base);
void					ft_float_rounder(char *str, int precision);
void					ft_float_g_rounder(t_flt_mstr *mflt, char *str,
		int precision);
void					ft_float_str_write_exp(char *str, int exp, int act);
void					ft_float_mflt_init(t_flt_mstr *mflt);
int						ft_putnbr_str(char *str, int nbr, int szmax);
int						ft_float_dbl_special(t_flt_mstr *mflt, char *str_out);
int						ft_float_ldbl_special(t_flt_mstr *mflt, char *str_out);
void					ft_float_write_str(char *str_out, t_flt_mstr *mflt);
void					ft_float_output_str(t_flt_mstr *mflt);
void					ft_float_extract_e_exp(t_flt_mstr *mflt, char *str);
void					ft_float_str_remove_dot(char *str_out, int act);
void					ft_float_str_insert_dot(char *str_out, int pos,
		int act);
void					ft_float_str_remove_leading_zero(char *str, int act,
		int e_exp);
void					ft_float_str_remove_trailing_zero(char *str, int act);
void					ft_float_str_addstart(char *str, int act, char c);

#endif
