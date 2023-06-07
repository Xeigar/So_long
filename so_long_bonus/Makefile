NAME = so_long
SRCS = so_long.c asset_handling.c clean_exit.c map_check.c map_utils.c move_player.c sprite_loader.c

FLAGS = -Wall -Werror -Wextra -g

CC = cc

RM = rm -f

LIBFT_PATH = libs/libft/

MLX_PATH = libs/mlx_linux/

LIBFT = -L $(LIBFT_PATH) -lft

MLX = -L $(MLX_PATH) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

OBJS = $(SRCS:.c=.o)

.c.o:
		${CC} ${FLAGS} -c $<

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(MLX) -o $(NAME)


all: $(NAME)

clean:
	make -C ${LIBFT_PATH} clean
	$(RM) $(OBJS)

fclean: clean
	make -C ${LIBFT_PATH} fclean
	${RM} ${NAME}

re: fclean all

.PHONY:all clean fclean re