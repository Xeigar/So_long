/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:44:23 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/10 15:44:15 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	wall_checker(t_vars *win)
{
	int	r;

	r = -1;
	while (++r <= win->map->col)
	{
		if (win->map->map_mx[0][r] != '1'
			|| win->map->map_mx[win->map->row][r] != '1')
			error_call("Error\nMissing Wall", win);
	}
	r = -1;
	while (++r <= win->map->row)
	{
		if (win->map->map_mx[r][0] != '1'
			|| win->map->map_mx[r][win->map->col] != '1')
			error_call("Error\nMissing Wall", win);
	}
}

void	char_check(t_vars *win, t_struct *checker)
{
	if (checker->p != 1)
		error_call("Error\nNo starting position", win);
	if (checker->c <= 0)
		error_call("Error\nNo colectibles", win);
	if (checker->e != 1)
		error_call("Error\nNo exit", win);
}

void	map_checker(t_vars *win, t_struct *checker)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (win->map->map_mx[++i])
	{
		j = -1;
		while (win->map->map_mx[i][++j])
		{
			if (win->map->map_mx[i][j] == 'P')
			{
				win->player = (t_point){i, j};
				checker->p += 1;
			}
			if (win->map->map_mx[i][j] == 'E')
				checker->e += 1;
			if (win->map->map_mx[i][j] == 'C')
				checker->c += 1;
		}
	}
}

void	get_map(int argc, char **argv, t_vars *win, t_struct *checker)
{
	int			fd;
	char		*line;

	if (argc != 2)
		error_call("Error\nWrong number of maps", win);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		error_call("Error\nWrong file type", win);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_call("Error\nOpening file", win);
	ft_bzero(checker, sizeof(t_struct));
	line = get_next_line(fd);
	if (!line || !*line)
		error_call("Error\nBlank file", win);
	checker->prev_size = ft_strlen(line);
	win->map->row = get_rows(argv[1]) - 1;
	win->map->col = checker->prev_size - 2;
	win->map->map_mx = matrix_generator(fd, win, line);
	close (fd);
}

void	map_project(int argc, char **argv, t_vars *win, t_struct *checker)
{
	get_map(argc, argv, win, checker);
	map_checker(win, checker);
	char_check(win, checker);
	wall_checker(win);
	path_check(win, checker);
}
