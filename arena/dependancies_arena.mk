# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_arena.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/31 09:59:29 by cgiron            #+#    #+#              #
#    Updated: 2019/09/10 14:04:58 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft/dependancies_libft.mk
-include ../shared_val.mk
-include ./shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_ARENA_DEP := 1

L_ARENA_DIR	:= arena

NAME_ARENA	:= corewar

SRC_ARENA = \
			main.c\
			memrevcpy.c\
			init.c\
			file_loading.c\
			binary_read.c\
			deassembler.c\
			file_closing.c\
			arena_populate.c\
			type_val.c\
			arena_val.c\
			player_give_process.c\
			memory_dump.c\
			operation_get_info.c\
			command_extract_register.c\
			command_extract_register_value.c\
			command_extract_direct_value.c\
			command_extract_indirect.c\
			command_get.c\
			command_valid_types.c\
			ex_command_st.c\
			ex_command_ld.c\
			ex_command_live.c\
			ex_command_add.c\
			ex_command_sub.c\
			ex_command_and.c\
			ex_command_or.c\
			ex_command_xor.c\
			ex_command_zjmp.c\
			ex_command_ldi.c\
			ex_command_sti.c\
			cursor_next_op.c\
			war.c\
			op.c\
			exit.c\

INC_ARENA					:= arena.h

DEPENDANCIES_ARENA_O		:= Makefile ./dependancies_$(L_ARENA_DIR).mk\
								 ./dependancies_$(L_ARENA_DIR)_object.mk\
								 ../shared_val.mk ./$(SHARE_INC_DIR)/op.h

DEPENDANCIES_ARENA_O		+= includes/*.h


DEPENDANCIES_ARENA			:= $(DEPENDANCIES_ARENA_O) \
 								$(addprefix ../,$(DEPENDANCIES_LIBFT_EXPORT))

INC_ARENA_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_ARENA))
SRC_ARENA_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_ARENA))
DEPENDANCIES_ARENA_E 		:= $(DEPENDANCIES_ARENA) $(SRC_ARENA_EXPORT) $(INC_ARENA_EXPORT)
DEPENDANCIES_ARENA_EXPORT	:= $(addprefix $(L_ARENA_DIR)/,$(DEPENDANCIES_ARENA_E))
