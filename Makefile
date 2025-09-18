NAME=so_long
CC=cc
CFLAGS=-Wall -Wextra -Werror
MLX_DIR=minilibx-linux
MLX=$(MLX_DIR)/libmlx_Linux.a
LIBFT_DIR=libft
LIBFT=$(LIBFT_DIR)/libft.a
INCLUDE=include
SRC=\
	src/main.c \
	src/utils.c \
	src/sl_utils.c \
	src/parse_map.c \
	src/validate_map.c \
	src/render.c \
	src/render_utils.c \
	src/validate_map2.c \
	src/validate_map3.c 


OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_DIR) $(OBJ) $(LIBFT) $(MLX) -L$(MLX_DIR) -lXext -lX11 -lm -o $(NAME)

$(MLX):
	@echo "Building MiniLibX in $(MLX_DIR) ..."
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
