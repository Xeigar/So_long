all:
	cc -g so_long.c asset_handling.c clean_exit.c map_check.c map_utils.c move_player.c libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz