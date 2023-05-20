/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:08:13 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/19 19:58:36 by tmoutinh         ###   ########.fr       */
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
	checker_initialize(&checker);
	line = get_next_line(fd);
	if (!line || !*line)
		error_call("Error Blank file");
	checker.prev_size = ft_strlen(line);
	win->map->map = ft_strdup("");
	while (line)
	{
		if (ft_strlen(line) != checker.prev_size)
			error_call("Error\nLines are not same size");
		checker.prev_size = ft_strlen(line);
		win->map->map = ft_strjoin(win->map->map, line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	map_checker(win, &checker);
}

void	build_map(w_vars *win)
{
	int	i;
	char	*p;
	int		a;
	void	*wall;

	i = 0;
	a = 20;
	p = "./Imagens and stuff/walls/wall_right.xpm";
	while(win->map->map[i])
	{
		if (win->map->map[i] == '1')
		{
			wall = mlx_xpm_to_image(win->map, &p, &a, &a);
			mlx_put_image_to_window(win->mlx, win->win, wall, a, a);
		}
		i++;
	}
}

void lauch_game(w_vars *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->map->col * SIZE, win->map->row * SIZE, "Game Name");
	if (!win->win)
		error_call("Error\nWindow not created");
	mlx_loop(win->mlx);
	
}

void	get_assets(w_vars *win)
{
	win->sp = (t_sprite*)ft_calloc(SPRITES, sizeof(t_sprite));
	if (!win->sp)
		error_call("Error\nSprite not allocated");
	win->sp[0].img = mlx_xpm_file_to_image(win->mlx, PW, &win->sp[0].width, &win->sp[0].height);
}

void	render_map(w_vars *win)
{
	mlx_put_image_to_window(win->mlx, win->win,	win->sp[0].img, win->sp[0].width * SIZE, win->sp[0].height * SIZE);
}

int	main(int argc, char **argv)
{
	w_vars	win;
	t_map	map;

	win.map = &map;
	get_map(argc, argv, &win);
	/*Only gets the Wall sprite*/
	get_assets(&win);
	lauch_game(&win);
	render_map(&win);
	return (0);
}
