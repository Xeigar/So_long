/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:08:13 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/10 15:44:25 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_assets(t_vars *win)
{
	load_terrain(win);
	load_enemy(win);
	load_player(win);
}

void	place(t_vars *win, t_point pos)
{
	t_sprite	sp;

	win->move_print = ft_itoa(win->moves);
	if (win->map->map_mx[pos.x][pos.y] == '1')
		sp = win->sp[W1];
	if (win->map->map_mx[pos.x][pos.y] == '0')
		sp = win->sp[F1];
	if (win->map->map_mx[pos.x][pos.y] == 'C')
		sp = win->sp[C1];
	if (win->map->map_mx[pos.x][pos.y] == 'E')
		sp = win->sp[E1];
	if (win->map->map_mx[pos.x][pos.y] == 'P')
		sp = win->player_sp[win->frame];
	if (win->map->map_mx[pos.x][pos.y] == 'V')
		sp = win->enemy_sp[win->frame];
	mlx_string_put(win->mlx, win->win,
		32 / 8, 32 / 3, (255 << 24) | (255 << 16)
		| (255 << 8) | 255, "Number of moves:");
	mlx_string_put(win->mlx, win->win,
		32 * 3.5, 32 / 3, (255 << 24) | (255 << 16)
		| (255 << 8) | 255, win->move_print);
	free(win->move_print);
	mlx_put_image_to_window(win->mlx, win->win, sp.img,
		pos.y * sp.width, pos.x * sp.height);
}

void	build_map(t_vars *win)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= win->map->row)
	{
		j = -1;
		while (++j <= win->map->col)
			place(win, (t_point){i, j});
	}
}

void	lauch_game(t_vars *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, (win->map->col + 1) * SIZE,
			(win->map->row + 1) * SIZE, "./so_long");
	if (!win->win)
		error_call("Error\nWindow not created", win);
}

int	get_sprite(t_point	a, t_vars *win)
{
	return (win->map->map_mx[a.x][a.y]);
}
