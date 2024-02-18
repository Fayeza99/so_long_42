NAME = so_long

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -ldl -lglfw -pthread -lm

MAIN = main.c
SRCS = errors/error1.c errors/error2.c errors/map_validity.c key_moves.c init.c utils.c

MLX_URL = https://github.com/codam-coding-college/MLX42.git
MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a

GNL_PATH = ./gnl
GNL = $(GNL_PATH)/get_next_line.a
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): lib $(SRCS) $(MAIN)
	cc $(CFLAGS) $(SRCS) $(MAIN) $(GNL) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

lib: $(MLX)
	make -sC $(GNL_PATH)
	make -sC $(LIBFT_PATH)

$(MLX):
	git clone $(MLX_URL)
	cd MLX42 && cmake -B build && cmake --build build

clean:
	make clean -sC $(GNL_PATH)
	make clean -sC $(LIBFT_PATH)
	rm -rf MLX42

fclean: clean
	rm -f $(NAME)
	make fclean -sC $(GNL_PATH)
	make fclean -sC $(LIBFT_PATH)

re: fclean all