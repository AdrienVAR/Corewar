NAME = corewar
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
SRC_DIR = src/
LIB_DIR = includes/libft/

SRC_FILES = main.c			\
			garbage_collector.c	

INC_FILES = $(shell find includes -regex ".\{1,200\}\.h" | xargs) \
			$(shell find includes/libft -regex ".\{1,200\}\.h" | xargs)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C includes/libft/
	$(CC) $(FLAGS) -Lincludes/libft -lft -o $@ $^
	make -C asm/

%.o: %.c $(INC_FILES)
	$(CC) $(FLAGS) -I includes/libft -o $@ -c $<

clean:
	make -C includes/libft clean
	make -C asm/ clean
	rm -f $(OBJ)

fclean: clean
	make -C includes/libft fclean
	make -C asm/ fclean
	rm -f $(NAME)

re: fclean all
