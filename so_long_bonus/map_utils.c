/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:40:39 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/03 12:48:34 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_rows(char *file)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	fd = open(file, O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		row++;
	}
	close (fd);
	return (row);
}

char	**matrix_generator(int fd, w_vars *win, char *line)
{
	int		r;
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * (win->map->row + 2));
	if (!temp)
		return (NULL);
	temp[win->map->row + 1] = NULL;
	r = -1;
	while (++r <= win->map->row)
	{
		temp[r] = line;
		line = get_next_line(fd);
	}
	return (temp);
}

void	flood_fill(char **map, t_point origin, t_struct *checker)
{
	if (map[origin.x][origin.y] != 'C' && map[origin.x][origin.y] != 'P'
	&& map[origin.x][origin.y] != 'E' && map[origin.x][origin.y] != '1'
	&& map[origin.x][origin.y] != 'F' && map[origin.x][origin.y] != '0'
	&& map[origin.x][origin.y] != 'V')
		checker->unk += 1;
	if (map[origin.x][origin.y] == '1' || map[origin.x][origin.y] == 'F'
	|| map[origin.x][origin.y] == 'V')
		return ;
	if (map[origin.x][origin.y] == 'P')
		checker->p_ck += 1;
	if (map[origin.x][origin.y] == 'E')
		checker->e_ck += 1;
	if (map[origin.x][origin.y] == 'C')
		checker->c_ck += 1;
	map[origin.x][origin.y] = 'F';
	flood_fill(map, (t_point){origin.x - 1, origin.y}, checker);
	flood_fill(map, (t_point){origin.x + 1, origin.y}, checker);
	flood_fill(map, (t_point){origin.x, origin.y - 1}, checker);
	flood_fill(map, (t_point){origin.x, origin.y + 1}, checker);
}

char	**matrix_duplicator(w_vars *win)
{
	int		c;
	int		r;
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * (win->map->row + 2));
	if (!temp)
		return (NULL);
	temp[win->map->row + 1] = NULL;
	r = -1;
	while (++r <= win->map->row)
	{
		temp[r] = (char *)malloc(sizeof(char) * win->map->col + 1);
		if (!temp[r])
			return (NULL);
		c = -1;
		while (++c <= win->map->col)
		{
			temp[r][c] = win->map->map_mx[r][c];
		}
	}
	return (temp);
}

void	path_check(w_vars *win, t_struct *checker)
{
	char	**temp;

	temp = matrix_duplicator(win);
	flood_fill(temp, win->player, checker);
	if (checker->c != checker->c_ck || checker->p != checker->p_ck
		|| checker->e != checker->e_ck)
	{
		temp_freer(temp);
		error_call("Error\nNo valid path", win);
	}
	if (checker->unk != 0)
	{
		temp_freer(temp);
		error_call("Error\nUnknown character", win);
	}
	checker->c_ck = 0;
	temp_freer(temp);
}
