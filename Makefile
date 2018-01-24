NAME = fractol

INCLUDE = fractal.h
LIBFT = libft/libft.a
LIBMLX = minilibx_macos/libmlx.a

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I includes -I libft/includes
LDFLAGS += -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

FRACTALDR = fractal.c \
			init.c \
			julia.c \
			serpienski.c \
			mandelbrot.c \

OBJ = $(FRACTALDR:.c=.o)

all : $(NAME)

$(LIBFT):
		@make -C libft/

$(LIBMLX):
		@make -C minilibx_macos

$(OBJ): %.o:%.c
		@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
		@$(CC) $(LDFLAGS) -o $@ $^
		@echo "Compiled Executable"

clean:
		@rm -rf $(OBJ)
		@make -C libft clean
		@make -C minilibx_macos clean
		@echo "Object Files Removed"

fclean: clean
		@rm -rf $(NAME)
		@make -C libft fclean
		@echo "libft.a Removed"

re: fclean all
