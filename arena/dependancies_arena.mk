# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_arena.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/31 09:59:29 by cgiron            #+#    #+#              #
#    Updated: 2019/08/31 10:05:23 by cgiron           ###   ########.fr        #
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
			main.c
INC_ARENA					:= arena.h

DEPENDANCIES_ARENA_O		:= Makefile ./dependancies_$(L_ARENA_DIR).mk\
								 ./dependancies_$(L_ARENA_DIR)_object.mk\
								 ../shared_val.mk

DEPENDANCIES_ARENA_O		+= includes/*.h


DEPENDANCIES_ARENA			:= $(DEPENDANCIES_ARENA_O) \
 								$(addprefix ../,$(DEPENDANCIES_LIBFT_EXPORT))

INC_ARENA_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_ARENA))
SRC_ARENA_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_ARENA))
DEPENDANCIES_ARENA_E 		:= $(DEPENDANCIES_ARENA) $(SRC_ARENA_EXPORT) $(INC_ARENA_EXPORT)
DEPENDANCIES_ARENA_EXPORT	:= $(addprefix $(L_ARENA_DIR)/,$(DEPENDANCIES_ARENA_E))
