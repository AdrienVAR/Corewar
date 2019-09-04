# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_asm.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/31 09:59:29 by cgiron            #+#    #+#              #
#    Updated: 2019/09/02 11:11:57 by cgiron           ###   ########.fr        #
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
		clean_exit.c\
		main.c\
		checker_champ.c\
		parsing.c

INC_ASM					:= asm.h

DEPENDANCIES_ASM_O		:= Makefile ./dependancies_$(L_ASM_DIR).mk\
								 ./dependancies_$(L_ASM_DIR)_object.mk\
								 ../shared_val.mk ./$(SHARE_INC_DIR)/op.h

DEPENDANCIES_ASM_O		+= includes/*.h


DEPENDANCIES_ASM			:= $(DEPENDANCIES_ASM_O) \
 								$(addprefix ../,$(DEPENDANCIES_LIBFT_EXPORT))

INC_ASM_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_ASM))
SRC_ASM_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_ASM))
DEPENDANCIES_ASM_E 		:= $(DEPENDANCIES_ASM) $(SRC_ASM_EXPORT) $(INC_ASM_EXPORT)
DEPENDANCIES_ASM_EXPORT	:= $(addprefix $(L_ASM_DIR)/,$(DEPENDANCIES_ASM_E))
