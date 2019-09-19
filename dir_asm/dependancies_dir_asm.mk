# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_asm.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/31 09:59:29 by cgiron            #+#    #+#              #
#    Updated: 2019/09/19 14:56:42 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft/dependancies_libft.mk
-include ../shared_val.mk
-include ./shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_ASM_DEP := 1

L_ASM_DIR	:= dir_asm

NAME_ASM	:= asm

SRC_ASM = \
		check_extention.c\
		check_label.c\
		check_digits.c\
		check_valid_type.c\
		clean_exit.c\
		writing.c\
		writing_header.c\
		writing_op.c\
		main.c\
		check_header.c\
		check_asm.c\
		check_op.c\
		split_header_line.c\
		split_op_line.c\
		op.c\
		parsing.c\
		check_typecode.c\
		fill_label.c\

INC_ASM					:= asm.h op.h libft/libft.h libft/get_next_line.h libft/ft_printf.h

DEPENDANCIES_ASM_O		:= Makefile ./dependancies_$(L_ASM_DIR).mk\
							../shared_val.mk

DEPENDANCIES_ASM			:= $(DEPENDANCIES_ASM_O) \
 								$(addprefix ../,$(DEPENDANCIES_LIBFT_EXPORT))\

INC_ASM_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_ASM))
SRC_ASM_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_ASM))
DEPENDANCIES_ASM_E 		:= $(DEPENDANCIES_ASM) $(SRC_ASM_EXPORT) $(INC_ASM_EXPORT)
DEPENDANCIES_ASM_EXPORT	:= $(addprefix $(L_ASM_DIR)/,$(DEPENDANCIES_ASM_E))
