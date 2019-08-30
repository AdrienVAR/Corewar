NAME = asm
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
SRC_DIR = src/
LIB_DIR = ../includes/libft/

SRC_FILES = main.c				\
			clean_exit.c		\
			check_extention.c	\
			parsing.c			\

INC_FILES = $(shell find ../includes -regex ".\{1,200\}\.h" | xargs)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -L ../includes/libft -lft -o $@ $^

%.o: %.c $(INC_FILES)
	$(CC) $(FLAGS) -I ../includes/libft -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
