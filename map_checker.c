/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:07:13 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/24 17:58:08 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker_initialize(t_struct *checker)
{
	checker->prev_size = 0;
	checker->p = 0 ;
	checker->c = 0;
	checker->e = 0;
	checker->p_ck = 0;
	checker->c_ck = 0;
	checker->e_ck = 0;
}

void	error_call(char *message)
{
	perror(message);
	exit(1);
}

void	wall_checker(w_vars *win, int wid)
{
	int	len;
	int	line;
	int	colu;
	int	i;

	len = 0;
	while(win->map->map_txt[len] != '\n')
		len++;
	win->map->col = len - 1; //12
	win->map->row = (wid - 1)/ (1 + len);//4
	i = 0;
	wid = 0;
	while (wid <= win->map->row)
	{
		len = 0;
		while (len <= win->map->col + 1)
		{
			if ((wid == 0 || wid == win->map->row) 
			|| (len == 0 || len == win->map->col))
				if (win->map->map_txt[i] != '1' && win->map->map_txt[i] != '\n')
					error_call("Error\nMissing wall");
			len++;
			i++;
		}
		wid++;
	}
}

char	**matrix_generator(w_vars *win)
{
	int	c;
	int	r;
	int	pos;
	char **temp;

	temp =(char**)malloc(sizeof(char*) * (win->map->row + 2));
	if (!temp)
		return (NULL);
	temp[win->map->row + 1] = NULL;
	r = 0;
	pos = 0;
	while (r <= win->map->row)
	{
		temp[r] =(char*)malloc(sizeof(char) * win->map->col);
		if (!temp[r])
			return (NULL);
		c = 0;
		while (c < win->map->col + 1)
		{
			if (win->map->map_txt[pos] == '\n')
			{
				c = 0;
				pos++;
			}
			temp[r][c] = win->map->map_txt[pos];
			if (temp[r][c] == 'P')
			{
				win->player.x = r;
				win->player.y = c;
			}
			c++;
			pos++;
		}
		r++;
	}
	return(temp);
}


void	flood_fill(char** map, t_point origin, t_struct *checker)
{
	if (map[origin.x][origin.y] == '1' || map[origin.x][origin.y] == 'F')
		return ;
	if (map[origin.x][origin.y] == 'P')
		checker->p_ck += 1;
	if (map[origin.x][origin.y] == 'E')
		checker->e_ck += 1;
	if (map[origin.x][origin.y] == 'C')
		checker->c_ck += 1;
	if (map[origin.x][origin.y] != 'C' && map[origin.x][origin.y] != 'P'
	&& map[origin.x][origin.y] != 'E' && map[origin.x][origin.y] != '1'
	&& map[origin.x][origin.y] != 'F' && map[origin.x][origin.y] != '0')
		error_call("Error\nUnknown character");
	map[origin.x][origin.y] = 'F';
	flood_fill(map, (t_point){origin.x - 1, origin.y}, checker);
	flood_fill(map, (t_point){origin.x + 1, origin.y}, checker);
	flood_fill(map, (t_point){origin.x, origin.y - 1}, checker);
	flood_fill(map, (t_point){origin.x, origin.y + 1}, checker);
}

void path_check(w_vars *win, t_struct *checker)
{
	char **temp;

	temp = matrix_generator(win);
	flood_fill(temp, win->player,checker);
	if (checker->c != checker->c_ck || checker->p != checker->p_ck
	|| checker->e != checker->e_ck)
		error_call("Error\nNo valid path");
	free(temp);
}

void	map_checker(w_vars *win, t_struct *checker)
{
	int	i;

	i = 0;
	while(win->map->map_txt[i])
	{
		if (win->map->map_txt[i] == 'P')
			checker->p += 1;
		if (win->map->map_txt[i] == 'E')
			checker->e += 1;
		if (win->map->map_txt[i] == 'C')
			checker->c += 1;
		if (win->map->map_txt[i] == '0')
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
	printf("%s", win->map->map_txt);/*used just to visualize the map*/
	wall_checker(win, i);
	win->map->map_mx = matrix_generator(win);
	path_check(win, checker);
}
