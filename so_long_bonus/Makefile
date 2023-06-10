NAME = so_long
SRCS = so_long_bonus.c asset_handling_bonus.c clean_exit_bonus.c map_check_bonus.c map_utils_bonus.c move_player_bonus.c sprite_loader_bonus.c

FLAGS = -Wall -Werror -Wextra -g

CC = cc

RM = rm -f

LIBFT_PATH = ../so_long/libs/libft/

MLX_PATH = ../so_long/libs/mlx_linux/

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
