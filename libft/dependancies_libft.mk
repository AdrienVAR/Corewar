# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_libft.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 10:08:33 by cgiron            #+#    #+#              #
#    Updated: 2019/08/07 09:40:05 by cgiron           ###   ########.fr        #
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

SRC_LIBFT = ft_abs.c\
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

INC_LIBFT					:= libft.h get_next_line.h

DEPENDANCIES_LIBFT			:= Makefile ./dependancies_$(L_LIBFT_DIR).mk\
								./dependancies_$(L_LIBFT_DIR)_object.mk\
								../shared_val.mk
INC_LIBFT_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_LIBFT))
SRC_LIBFT_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_LIBFT))
DEPENDANCIES_LIBFT_E 		:= $(DEPENDANCIES_LIBFT) $(SRC_LIBFT_EXPORT) $(INC_LIBFT_EXPORT)
DEPENDANCIES_LIBFT_EXPORT	:= $(addprefix $(L_LIBFT_DIR)/,$(DEPENDANCIES_LIBFT_E))
