

include ../shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
	$(error SHARE_VAL not included)
endif

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=$(OPTI_FLAGS)

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
