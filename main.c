/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:08:13 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/25 17:34:26 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*A funcao vai contar o tamanho das linhas e passar o conteudo
do mapa para win->map, NOT WORKING FOR BLANK DOCUMENT*/
void	get_map(int argc, char **argv, w_vars *win)
{
	int			fd;
	t_struct	checker;
	char		*line;

	if (argc != 2)
		error_call("Error Wrong number of maps");
	if(!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		error_call("Error Wrong file type");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_call("Error opening file");
	//checker_initialize(&checker);
	line = get_next_line(fd);
	if (!line || !*line)
		error_call("Error Blank file");
	checker.prev_size = ft_strlen(line);
	win->map->map_txt = ft_strdup("");
	while (line)
	{
		if (ft_strlen(line) != checker.prev_size)
			error_call("Error\nLines are not same size");
		checker.prev_size = ft_strlen(line);
		win->map->map_txt = ft_strjoin(win->map->map_txt, line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	map_checker(win, &checker);
}

void	get_assets(w_vars *win)
{
	win->sp = (t_sprite*)ft_calloc(SPRITES, sizeof(t_sprite));
	if (!win->sp)
		error_call("Error\nSprite not allocated");
	win->sp[W1].img = mlx_xpm_file_to_image(win->mlx, PW, &(win->sp[W1].width), &(win->sp[W1].height));
	win->sp[F1].img = mlx_xpm_file_to_image(win->mlx, PF, &(win->sp[F1].width), &(win->sp[F1].height));
	win->sp[C1].img = mlx_xpm_file_to_image(win->mlx, PC, &(win->sp[C1].width), &(win->sp[C1].height));
	win->sp[E1].img = mlx_xpm_file_to_image(win->mlx, PE, &(win->sp[E1].width), &(win->sp[E1].height));
	win->sp[P1].img = mlx_xpm_file_to_image(win->mlx, PP, &(win->sp[P1].width), &(win->sp[P1].height));
}

/*Preciso de ajustar a escala as coins estão a fugir*/
void place(w_vars *win, t_point pos)
{
	t_sprite	sp;

	if (win->map->map_mx[pos.x][pos.y] == '1')
		sp = win->sp[W1];
	if (win->map->map_mx[pos.x][pos.y] == '0')
		sp = win->sp[F1];
	if (win->map->map_mx[pos.x][pos.y] == 'C')
		sp = win->sp[C1];
	if (win->map->map_mx[pos.x][pos.y] == 'E')
		sp = win->sp[E1];
	if (win->map->map_mx[pos.x][pos.y] == 'P')
		sp = win->sp[P1];
	mlx_put_image_to_window(win->mlx, win->win, sp.img, pos.y * sp.width, pos.x * sp.height);
}

void	build_map(w_vars *win)
{
	int	i;
	int j;

	i = 0;
	while(i <= win->map->row)
	{
		j = 0;
		while (j <= win->map->col)
		{
			place(win, (t_point){i, j});
			j++;
		}
		i++;
		
	}
}

void lauch_game(w_vars *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, (win->map->col + 1) * SIZE, (win->map->row + 1) * SIZE, "Game Name");
	if (!win->win)
		error_call("Error\nWindow not created");
}

void	clean_map(w_vars *win)
{
	size_t	i;
	
	if(!win->map->map_mx)
		return;
	i = 0;
	while(win->map->map_mx[i])
	{
		free(win->map->map_mx[i]);
		i++;
	}
	if(!win->map->map_txt)
		return;
	free(win->map->map_txt);
}

void	clean_sprites(w_vars *win)
{
	int	i;

	i = -1;
	while (++i < SPRITES)
		mlx_destroy_image(win->mlx, win->sp[i].img);
	free (win->sp);
}

void	exit_game(w_vars *win)
{
	if (!win)
		return ;
	if (win->map)
		clean_map(win);
	if (win->sp)
		clean_sprites(win);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
		mlx_destroy_display(win->mlx);
	free(win->mlx);
}

int	quit_game(w_vars *win)
{
	exit_game(win);
	exit(EXIT_SUCCESS);
}

int	get_key(int keycode, w_vars *win)
{
	printf("Move input\n");
	if (keycode == ESC)
		quit_game(win);
	if (keycode == A || keycode == LEFT)
		win->player_next = (t_point){win->player.x, win->player.y - 1};
	if (keycode == D || keycode == RIGHT)
		win->player_next = (t_point){win->player.x, win->player.y + 1};
	if (keycode == W || keycode == UP)
	{
		if (win->map->map_mx[win->player.x - 2][win->player.y] != '1')
			win->player_next = (t_point){win->player.x - 2, win->player.y};
		else
			win->player_next = (t_point){win->player.x - 1, win->player.y};
	}
	return(keycode);
}

void	move_player(w_vars *win, t_map *map)
{
	if (map->map_mx[win->player_next.x][win->player_next.y] != 'E')
	{
		map->map_mx[win->player_next.x][win->player_next.y] = 'P';
		map->map_mx[win->player.x][win->player.y] = '0';
	}
	build_map(win);
	/*This does the same thing as build_map the difference is the number of
	sprites that are changed*/
	//place(win, (t_point){win->player.x, win->player.y});
	//place(win, (t_point){win->player_next.x, win->player_next.y});
	win->player = win->player_next;
}

int	get_sprite(t_point	a, w_vars *win)
{
	return (win->map->map_mx[a.x][a.y]);
}

int	render_move(w_vars *win)
{
	static int	moves;

	if (win->player.x == win->player_next.x && win->player.y == win->player_next.y)
		return (0);
	if (get_sprite(win->player_next, win) == '1')
		return (0);
	ft_putstr_fd("Number of moves :", 1);
	ft_putnbr_fd(++moves, 1);
	ft_putchar_fd('\n', 1);
	move_player(win, win->map);
	if (win->map->map_mx[win->player.x + 1][win->player.y] == '0') {
		win->player_next = (t_point){win->player.x + 1, win->player.y};
		move_player(win, win->map); // Recursive call to continue descending
	}
	return (0);
}


int	main(int argc, char **argv)
{
	w_vars	win;
	t_map	map;

	win.map = &map;
	get_map(argc, argv, &win);
	/*Only gets the Wall sprite*/
	lauch_game(&win);
	get_assets(&win);
	build_map(&win);
	win.player_next = (t_point){0, 0};
	mlx_hook(win.win, 2, (1L<<0), get_key, &win);
	mlx_hook (win.win, 17, (1L<<17), quit_game, &win);
	mlx_loop_hook(win.mlx, render_move, &win);
	mlx_loop(win.mlx);
	return (0);
}
