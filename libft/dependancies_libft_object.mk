# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_libft_object.mk                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 10:11:30 by cgiron            #+#    #+#              #
#    Updated: 2019/09/18 09:23:31 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_bzero.o: libft.h
ft_isalnum.o: libft.h
ft_itoa.o: libft.h
ft_lstadd.o: libft.h
ft_lstaddend.o: libft.h
ft_lstdel.o: libft.h
ft_lstdelone.o: libft.h
ft_lstiter.o: libft.h
ft_lstmap.o: libft.h
ft_lstnew.o: libft.h
ft_memalloc.o: libft.h
ft_memchr.o: libft.h
ft_putendl.o: libft.h
ft_putendl_fd.o: libft.h
ft_putnbr.o: libft.h
ft_putnbr_fd.o: libft.h
ft_putstr.o: libft.h
ft_putstr_fd.o: libft.h
ft_split_whitespace.o: libft.h
ft_sqweeze.o: libft.h
ft_strdel.o: libft.h
ft_strdup.o: libft.h
ft_strequ.o: libft.h
ft_strjoin.o: libft.h
ft_strjoin_free.o: libft.h
ft_strlcat.o: libft.h
ft_strmap.o: libft.h
ft_strmapi.o: libft.h
ft_strncpy.o: libft.h
ft_strndup.o: libft.h
ft_strnequ.o: libft.h
ft_strnew.o: libft.h
ft_strnjoin.o: libft.h
ft_strsplit.o: libft.h
ft_strsplitn.o: libft.h
ft_strsub.o: libft.h
ft_strtrim.o: libft.h
ft_tab_strrev.o: libft.h
ft_tab_strsort.o: libft.h
ftoa/ft_float_apply_exp.o: ftoa.h libft.h
ftoa/ft_float_bin_dbl_extract.o: ftoa.h libft.h
ftoa/ft_float_bin_ldbl_extract.o: ftoa.h libft.h
ftoa/ft_float_dbl_special.o: ftoa.h libft.h
ftoa/ft_float_extract_e_exp.o: ftoa.h
ftoa/ft_float_g_rounder.o: ftoa.h libft.h
ftoa/ft_float_get_mantissa.o: ftoa.h
ftoa/ft_float_ldbl_special.o: ftoa.h libft.h
ftoa/ft_float_mstr_init.o: ftoa.h
ftoa/ft_float_output_str.o: ftoa.h libft.h
ftoa/ft_float_rounder.o: ftoa.h libft.h
ftoa/ft_float_str_addstart.o: ftoa.h libft.h
ftoa/ft_float_str_insert_dot.o: ftoa.h libft.h
ftoa/ft_float_str_remove_dot.o: ftoa.h libft.h
ftoa/ft_float_str_remove_leading_zero.o: ftoa.h libft.h
ftoa/ft_float_str_remove_trailing_zero.o: ftoa.h
ftoa/ft_float_str_write_exp.o: ftoa.h
ftoa/ft_float_tab_op.o: ftoa.h
ftoa/ft_float_write_str.o: ftoa.h
ftoa/ft_ftoa_dbl.o: ftoa.h libft.h
ftoa/ft_ftoa_ldbl.o: ftoa.h libft.h
ftoa/ft_putnbr_str.o: ftoa.h libft.h
get_next_line.o: get_next_line.h libft.h
printf/ft_asprintf.o: ft_printf.h libft.h ftoa.h
printf/ft_buffer_digits_base.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_char.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_color.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_flt.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_flt_e.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_flt_g.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_int.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_n.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_np_str.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_percent.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_ptr.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_str.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_time.o: ft_printf.h libft.h ftoa.h
printf/ft_conv_unsigned_int.o: ft_printf.h libft.h ftoa.h
printf/ft_dprintf.o: ft_printf.h libft.h ftoa.h
printf/ft_fetch_char.o: ft_printf.h libft.h ftoa.h
printf/ft_fetch_flt.o: ft_printf.h libft.h ftoa.h
printf/ft_fetch_int.o: ft_printf.h libft.h ftoa.h
printf/ft_fetch_int_adr.o: ft_printf.h libft.h ftoa.h
printf/ft_fetch_ptr.o: ft_printf.h libft.h ftoa.h
printf/ft_fetch_str.o: ft_printf.h libft.h ftoa.h
printf/ft_fetch_time.o: ft_printf.h libft.h ftoa.h
printf/ft_fetch_u_int.o: ft_printf.h libft.h ftoa.h
printf/ft_flag_mngmt.o: ft_printf.h libft.h ftoa.h
printf/ft_flag_option_check.o: ft_printf.h libft.h ftoa.h libft.h ftoa.h
printf/ft_list.o: ft_printf.h libft.h ftoa.h
printf/ft_printf.o: ft_printf.h libft.h ftoa.h
printf/ft_specialty_list.o: ft_printf.h libft.h ftoa.h
printf/ft_sprintf.o: ft_printf.h libft.h ftoa.h
printf/ft_standard_padding.o: ft_printf.h libft.h ftoa.h
printf/ft_str_to_buffer.o: ft_printf.h libft.h ftoa.h
printf/ft_unicode.o: ft_printf.h libft.h ftoa.h
printf/type_prefixes.o: ft_printf.h libft.h ftoa.h
