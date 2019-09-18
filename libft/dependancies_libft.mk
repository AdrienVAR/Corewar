# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_libft.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 10:08:33 by cgiron            #+#    #+#              #
#    Updated: 2019/09/18 09:25:04 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ./shared_val.mk
-include ../shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_LIBFT_DEP := 1

L_LIBFT_DIR	:= libft

NAME_LIBFT	:= libft.a


SRC_PRINTF :=	\
	ft_asprintf.c\
	ft_buffer_digits_base.c\
	ft_conv_char.c\
	ft_conv_color.c\
	ft_conv_flt.c\
	ft_conv_flt_e.c\
	ft_conv_flt_g.c\
	ft_conv_int.c\
	ft_conv_n.c\
	ft_conv_np_str.c\
	ft_conv_percent.c\
	ft_conv_ptr.c\
	ft_conv_str.c\
	ft_conv_time.c\
	ft_conv_unsigned_int.c\
	ft_dprintf.c\
	ft_fetch_char.c\
	ft_fetch_flt.c\
	ft_fetch_int.c\
	ft_fetch_int_adr.c\
	ft_fetch_ptr.c\
	ft_fetch_str.c\
	ft_fetch_time.c\
	ft_fetch_u_int.c\
	ft_flag_mngmt.c\
	ft_flag_option_check.c\
	ft_int_size_base.c\
	ft_list.c\
	ft_printf.c\
	ft_specialty_list.c\
	ft_sprintf.c\
	ft_standard_padding.c\
	ft_str_to_buffer.c\
	ft_unicode.c\
	type_prefixes.c

SRC_PRINTF  := $(addprefix ./printf/,$(SRC_PRINTF))

SRC_FTOA :=	ft_float_apply_exp.c\
	ft_float_bin_dbl_extract.c\
	ft_float_bin_ldbl_extract.c\
	ft_float_dbl_special.c\
	ft_float_extract_e_exp.c\
	ft_float_g_rounder.c\
	ft_float_get_mantissa.c\
	ft_float_ldbl_special.c\
	ft_float_mstr_init.c\
	ft_float_output_str.c\
	ft_float_rounder.c\
	ft_float_str_addstart.c\
	ft_float_str_insert_dot.c\
	ft_float_str_remove_dot.c\
	ft_float_str_remove_leading_zero.c\
	ft_float_str_remove_trailing_zero.c\
	ft_float_str_write_exp.c\
	ft_float_tab_op.c\
	ft_float_write_str.c\
	ft_ftoa_dbl.c\
	ft_ftoa_ldbl.c\
	ft_putnbr_str.c

SRC_FTOA  := $(addprefix ./ftoa/,$(SRC_FTOA))

SRC_LIBFT = $(SRC_FTOA)\
	$(SRC_PRINTF)\
	ft_abs.c\
	ft_atoi.c\
	ft_atoi_base.c\
	ft_bzero.c \
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_lstadd.c\
	ft_lstaddend.c\
	ft_lstdel.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_max.c\
	ft_memalloc.c\
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c\
	ft_memmove.c \
	ft_memset.c \
	ft_min.c\
	ft_newstrtab.c\
	ft_power.c\
	ft_printbits.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_split_whitespace.c\
	ft_split_whitespace_len.c\
	ft_sqweeze.c\
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c\
	ft_strcmp.c\
	ft_strcpy.c \
	ft_strdel.c\
	ft_strdup.c \
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c \
	ft_strncmp.c\
	ft_strncpy.c \
	ft_strndup.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnjoin.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strrev.c\
	ft_strsplit.c\
	ft_strsplitn.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strswap.c\
	ft_strtabdel.c\
	ft_strtrim.c\
	ft_swap.c\
	ft_tab_len.c\
	ft_tab_strrev.c\
	ft_tab_strsort.c\
	ft_tolower.c\
	ft_toupper.c\
	get_next_line.c\
	ft_strjoin_free.c\
	ft_in_range.c

INC_LIBFT					:= libft.h get_next_line.h ft_printf.h ftoa.h

DEPENDANCIES_LIBFT			:= Makefile ./dependancies_$(L_LIBFT_DIR).mk\
								./dependancies_$(L_LIBFT_DIR)_object.mk\
								../shared_val.mk
INC_LIBFT_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_LIBFT))
SRC_LIBFT_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_LIBFT))
DEPENDANCIES_LIBFT_E 		:= $(DEPENDANCIES_LIBFT) $(SRC_LIBFT_EXPORT) $(INC_LIBFT_EXPORT)
DEPENDANCIES_LIBFT_EXPORT	:= $(addprefix $(L_LIBFT_DIR)/,$(DEPENDANCIES_LIBFT_E))
