/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:41:41 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/04 18:17:53 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_key(int keycode, w_vars *win)
{
	if (keycode == ESC)
		quit_game(win);
	if (keycode == A || keycode == LEFT)
		win->player_next = (t_point){win->player.x, win->player.y - 1};
	if (keycode == D || keycode == RIGHT)
		win->player_next = (t_point){win->player.x, win->player.y + 1};
	if (keycode == W || keycode == UP)
		win->player_next = (t_point){win->player.x - 1, win->player.y};
	if (keycode == S || keycode == DOWN)
		win->player_next = (t_point){win->player.x + 1, win->player.y};
	return (keycode);
}

void	move_player(w_vars *win, t_map *map)
{
	if (map->map_mx[win->player_next.x][win->player_next.y] != 'E')
	{
		if (map->map_mx[win->player_next.x][win->player_next.y] == 'V')
			quit_game(win);
		if (map->map_mx[win->player_next.x][win->player_next.y] == 'C')
			win->checker->c_ck += 1;
		map->map_mx[win->player_next.x][win->player_next.y] = 'P';
		map->map_mx[win->player.x][win->player.y] = '0';
		if (win->checker->c == win->checker->c_ck)
		{
			mlx_destroy_image(win->mlx, win->sp[E1].img);
			win->sp[E1].img = mlx_xpm_file_to_image(win->mlx, PO,
					&(win->sp[E1].width), &(win->sp[E1].height));
		}
	}
	if (map->map_mx[win->player_next.x][win->player_next.y] == 'E'
	&& win->checker->c == win->checker->c_ck)
		quit_game(win);
	build_map(win);
	win->player = win->player_next;
}

int	render_move(w_vars *win)
{
	if ((win->player.x == win->player_next.x
			&& win->player.y == win->player_next.y)
		|| (win->map->map_mx[win->player_next.x][win->player_next.y] == 'E'
		&& win->checker->c != win->checker->c_ck))
		return (0);
	if (get_sprite(win->player_next, win) == '1')
		return (0);
	win->moves += 1;
	move_player(win, win->map);
	return (0);
}

void	temp_freer(char **arr)
{
	int	a;

	a = 0;
	while (arr[a])
	{
		free(arr[a]);
		a++;
	}
	free(arr);
}
