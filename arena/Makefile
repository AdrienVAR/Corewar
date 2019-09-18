# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:56:45 by cgiron            #+#    #+#              #
#    Updated: 2019/09/18 21:39:40 by cizeur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./dependancies_arena.mk
include ../libft/dependancies_libft.mk
include ../shared_val.mk

ifeq ($(CHECK_ARENA_DEP),)
$(error ARENA_DEPENDANCIES not included)
endif
ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif
ifeq ($(CHECK_LIBFT_DEP),)
$(error LIBFT_DEPENDANCIES not included)
endif

L_FT    := ../libft
EXFLAGS := -L $(L_FT) -lft $(SHARE_FLAGS)
SIMULINK := $(SHARE_INC_DIR)/$(NAME_LIBFT)

NAME 	:= $(NAME_ARENA)
SRC_DIR := $(SHARE_SRC_DIR)
INC_DIR := $(SHARE_INC_DIR)
OBJ_DIR := $(SHARE_OBJ_DIR)
SRC 	:= $(SRC_ARENA)
OBJ		:= $(patsubst %.c,%.o,$(SRC))
DEP		:= $(patsubst %.o,%.d,$(OBJ))
vpath	%c $(SRC_DIR)/ex_command


CC      := gcc
CFLAGS  := $(SHARE_FLAGS)

.PHONY: all clean fclean re debug simulink

all: $(NAME)

simulink:
	rm -rf	$(INC_DIR)/$(L_LIBFT_DIR)
	ln -s	../$(L_FT)/$(INC_DIR) $(INC_DIR)/$(L_LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

%.o:%.c $(DEPENDANCIES_ARENA_O)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(OPTI_FLAGS) $(CFLAGS) -c $< -o  $(addprefix $(OBJ_DIR)/,$@)

$(OBJ_DIR)/%.d:%.c $(DEPENDANCIES_ARENA_O)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(OPTI_FLAGS) $(CFLAGS) -MM -MG -c $< -o $@

$(NAME): $(OBJ) $(DEPENDANCIES_ARENA)
	$(MAKE) -C $(L_FT) "OPTI_FLAGS=$(OPTI_FLAGS)" --no-print-directory
	$(CC) $(OPTI_FLAGS) $(CFLAGS) $(EXFLAGS)  $(addprefix $(OBJ_DIR)/,$(OBJ)) -o $(NAME)

clean:
	$(MAKE) clean -C $(L_FT) --no-print-directory
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(L_FT) --no-print-directory
	rm -f $(NAME)

debug: OPTI_FLAGS := $(SHARE_DEBUG)
debug: re clean

re: fclean all

include  $(addprefix $(OBJ_DIR)/,$(DEP))

