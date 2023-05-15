/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:08:13 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/15 18:26:47 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker_initialize(t_struct *checker, w_vars *win)
{
	checker->prev_size = 0;
	checker->p = 0 ;
	checker->c = 0;
	checker->e = 0;
}

void	error_call(char *message)
{
	perror(message);
	exit(1);
}

void wall_checker(w_vars *win, int wid)
{
	int	len;
	int	line;
	int	colu;
	int	i;

	len = 0;
	while(*win->map != '\n')
	{
		len++;
		win->map++;
	}
	wid = wid / len;
	line = len;
	colu = wid;
	i = 0;
	while (wid != 0 && len != 0)
	{
		len = line;
		while (len != 0)
		{
			if ((wid == colu || wid == 0) || (len == 0 || len == line))
				if (win->map[i] != '1')
					error_call("Error\nMissing wall");
			len--;
			i++;
		}
		wid--;
	}
}

/*Missing the verification of walls and valid path*/
void map_checker(w_vars *win, t_struct *checker)
{
	int	i;

	i = 0;
	while(win->map[i])
	{
		if (win->map[i] == 'P')
			checker->p += 1;
		if (win->map[i] == 'E')
			checker->e += 1;
		if (win->map[i] == 'C')
			checker->c += 1;
		if (win->map[i] == '0')
			checker->free += 1;
		i++;
	}
	if (checker->p != 1)
		error_call("Error\nOn starting position");
	if (checker->free <= 0)
		error_call("Error\nNo free space");
	if (checker->c <= 0)
		error_call("Error\nNo colectibles");
	if (checker->e != 1)
		error_call("Error\nOn exit");
	wall_checker(win, i);
}

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
	checker_initialize(&checker, win);
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
	printf("%s", win->map);/*used just to visualize the map*/
	close (fd);
	map_checker(win, &checker);
}

int	main(int argc, char **argv)
{
	w_vars	win;

	get_map(argc, argv, &win);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1920, 1080, "Game Name");
	mlx_loop(win.mlx);
	return (0);
}
