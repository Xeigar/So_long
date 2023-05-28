/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:08:13 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/28 15:47:54 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_assets(w_vars *win)
{
	win->sp = (t_sprite *)ft_calloc(SPRITES, sizeof(t_sprite));
	if (!win->sp)
		error_call("Error\nSprite not allocated", win);
	win->sp[W1].img = mlx_xpm_file_to_image(win->mlx, PW, &(win->sp[W1].width),
			&(win->sp[W1].height));
	win->sp[F1].img = mlx_xpm_file_to_image(win->mlx, PF, &(win->sp[F1].width),
			&(win->sp[F1].height));
	win->sp[C1].img = mlx_xpm_file_to_image(win->mlx, PC, &(win->sp[C1].width),
			&(win->sp[C1].height));
	win->sp[E1].img = mlx_xpm_file_to_image(win->mlx, PE, &(win->sp[E1].width),
			&(win->sp[E1].height));
	win->sp[P1].img = mlx_xpm_file_to_image(win->mlx, PP, &(win->sp[P1].width),
			&(win->sp[P1].height));
}

void	place(w_vars *win, t_point pos)
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
	mlx_put_image_to_window(win->mlx, win->win, sp.img,
		pos.y * sp.width, pos.x * sp.height);
}

void	build_map(w_vars *win)
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

void	lauch_game(w_vars *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, (win->map->col + 1) * SIZE,
			(win->map->row + 1) * SIZE, "./so_long");
	if (!win->win)
		error_call("Error\nWindow not created", win);
}

int	get_sprite(t_point	a, w_vars *win)
{
	return (win->map->map_mx[a.x][a.y]);
}
