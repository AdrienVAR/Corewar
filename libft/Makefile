# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:01:34 by cgiron            #+#    #+#              #
#    Updated: 2019/09/30 19:26:17 by cgiron           ###   ########.fr        #
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
INC		:= $(INC_LIBFT)
OBJ		:= $(patsubst %.c,%.o,$(SRC))
DEPENDANCIES:= $(DEPENDANCIES_LIBFT)

CC      := gcc
CFLAGS  := $(SHARE_FLAGS)

vpath	%c $(SRC_DIR)/printf
vpath	%c $(SRC_DIR)/ftoa

.PHONY: all clean fclean re debug simulink depend

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o:%.c $(DEPENDANCIES_LIBFT)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(OPTI_FLAGS) $(CFLAGS)  -o $(OBJ_DIR)/$@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(addprefix $(OBJ_DIR)/,$(OBJ))
	ranlib $(NAME)

debug: OPTI_FLAGS := $(SHARE_DEBUG)
debug: re clean

depend: depend.mk

depend.mk: $(SRC) $(INC)
		rm -f ./depend.mk
		$(CC) $(CFLAGS) -MM $^ -MG >> ./depend.mk;

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), simulink)
ifneq ($(MAKECMDGOALS), fclean)
ifneq ($(MAKECMDGOALS), re)
include   depend.mk
endif
endif
endif
endif

re: fclean depend all

clean:
	rm -f ./depend.mk
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
