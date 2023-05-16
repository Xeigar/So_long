/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:08:13 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/16 18:13:24 by tmoutinh         ###   ########.fr       */
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
	win->map = ft_strdup("");
	while (line)
	{
		if (ft_strlen(line) != checker.prev_size)
			error_call("Error\nLines are not same size");
		checker.prev_size = ft_strlen(line);
		win->map = ft_strjoin(win->map, line);
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
	while(win->map[i])
	{
		if (win->map[i] == '1')
		{
			wall = mlx_xpm_to_image(win->map, &p, &a, &a);
			mlx_put_image_to_window(win->mlx, win->win, wall, a, a);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	w_vars	win;

	win.w = 1920;
	win.h = 1080;
	get_map(argc, argv, &win);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.w, win.h, "Game Name");
	if (!win.win)
		return (-1);
	build_map(&win);
	mlx_loop(win.mlx);
	return (0);
}
