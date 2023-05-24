/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:08:13 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/24 20:59:24 by tmoutinh         ###   ########.fr       */
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

int	keybinding(int keycode, w_vars *win)
{
	if (keycode == ESC)
		exit_game(win);
	if (keycode == W || keycode == UP)
		(t_point){win->player_next.x + 1, win->player_next.y};
		
	if (keycode == A || keycode == LEFT);
	if (keycode == D || keycode == RIGHT);
	
	return(keycode);
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
	//mlx_key_hook(&win.win, keybinding,&win);
	mlx_loop(win.mlx);
	return (0);
}
