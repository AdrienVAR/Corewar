# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:01:34 by cgiron            #+#    #+#              #
#    Updated: 2019/09/19 10:44:03 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./dependancies_libft.mk
-include ../shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif
ifeq ($(CHECK_LIBFT_DEP),)
$(error LIBFT_DEPENDANCIES not included)
endif

NAME 	:= $(NAME_LIBFT)
SRC_DIR := $(SHARE_SRC_DIR)
INC_DIR := $(SHARE_INC_DIR)
OBJ_DIR := $(SHARE_OBJ_DIR)
SRC 	:= $(SRC_LIBFT)
OBJ		:= $(patsubst %.c,%.o,$(SRC))
DEPENDANCIES:= $(DEPENDANCIES_LIBFT)

CC      := gcc
CFLAGS  := $(SHARE_FLAGS)

vpath	%c $(SRC_DIR)/printf
vpath	%c $(SRC_DIR)/ftoa

.PHONY: all clean fclean re debug simulink depend

all: $(NAME)

DEP		:= $(patsubst %.o,%.d,$(OBJ))
ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), simulink)
ifneq ($(MAKECMDGOALS), fclean)
ifneq ($(MAKECMDGOALS), re)
include  $(addprefix $(OBJ_DIR)/,$(DEP))
endif
endif
endif
endif

depend: $(addprefix $(OBJ_DIR)/,$(DEP))

re: fclean depend all

$(OBJ_DIR)/%.d:%.c $(DEPENDANCIES_ARENA_O)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(OPTI_FLAGS) $(CFLAGS) -MM -MG -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o:%.c $(DEPENDANCIES_LIBFT)
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/printf $(OBJ_DIR)/ftoa
	$(CC) $(OPTI_FLAGS) $(CFLAGS)  -o $(OBJ_DIR)/$@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(addprefix $(OBJ_DIR)/,$(OBJ))
	ranlib $(NAME)

debug: OPTI_FLAGS := $(SHARE_DEBUG)
debug: re clean

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
