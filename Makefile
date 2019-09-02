# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:16:41 by cgiron            #+#    #+#              #
#    Updated: 2019/09/02 11:27:22 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./libft/dependancies_libft.mk
include ./arena/dependancies_arena.mk
include ./asm/dependancies_asm.mk
include ./shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
	$(error SHARE_VAL not included)
endif
ifeq ($(CHECK_LIBFT_DEP),)
	$(error LIBFT_DEPENDANCIES not included)
endif
ifeq ($(CHECK_ARENA_DEP),)
	$(error ARENA_DEPENDANCIES not included)
endif
ifeq ($(CHECK_ASM_DEP),)
	$(error ASM_DEPENDANCIES not included)
endif

NAME := $(NAME_ARENA) $(NAME_ASM)

L_NAME = "NAME_ARENA=../$(NAME_ARENA)"
V_NAME = "NAME_ASM=../$(NAME_ASM)"

.PHONY: all clean fclean re debug

all : $(NAME)

STD_DEPENDANCY := $(DEPENDANCIES_LIBFT_EXPORT)

$(NAME_ARENA) : $(DEPENDANCIES_ARENA_EXPORT) $(STD_DEPENDANCY)
	$(MAKE) -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) -C $(L_ARENA_DIR) $(L_NAME) --no-print-directory

$(NAME_ASM) : $(DEPENDANCIES_ASM_EXPORT) $(STD_DEPENDANCY)
	$(MAKE) -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE)  -C $(L_ASM_DIR) $(V_NAME) --no-print-directory

clean:
	$(MAKE) clean -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) clean -C $(L_ARENA_DIR) --no-print-directory
	$(MAKE) clean -C $(L_ASM_DIR) --no-print-directory

fclean:
	$(MAKE) fclean -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) fclean -C $(L_ARENA_DIR) --no-print-directory
	$(MAKE) fclean -C $(L_ASM_DIR) --no-print-directory
	rm -f $(NAME)

simulink:
	$(MAKE) simulink -C $(L_ARENA_DIR) --no-print-directory
	$(MAKE) simulink -C $(L_ASM_DIR) --no-print-director/

debug:
	$(MAKE) debug -C $(L_ARENA_DIR) $(L_NAME) --no-print-directory
	$(MAKE) debug -C $(L_ASM_DIR) $(V_NAME) --no-print-directory

re: fclean all
