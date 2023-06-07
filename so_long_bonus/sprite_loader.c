/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:52:23 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/04 18:25:51 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_enemy(w_vars *win)
{
	win->enemy_sp = (t_sprite *)ft_calloc(PLAYER, sizeof(t_sprite));
	if (!win->enemy_sp)
		error_call("Error\nEnemy sprite not allocated", win);
	win->enemy_sp[0].img = mlx_xpm_file_to_image(win->mlx, PD1,
			&(win->enemy_sp[0].width), &(win->enemy_sp[0].height));
	win->enemy_sp[1].img = mlx_xpm_file_to_image(win->mlx, PD2,
			&(win->enemy_sp[1].width), &(win->enemy_sp[1].height));
	win->enemy_sp[2].img = mlx_xpm_file_to_image(win->mlx, PD3,
			&(win->enemy_sp[2].width), &(win->enemy_sp[2].height));
	win->enemy_sp[3].img = mlx_xpm_file_to_image(win->mlx, PD3,
			&(win->enemy_sp[3].width), &(win->enemy_sp[3].height));
}

void	load_player(w_vars *win)
{
	win->player_sp = (t_sprite *)ft_calloc(PLAYER, sizeof(t_sprite));
	if (!win->player_sp)
		error_call("Error\nPlayer sprite not allocated", win);
	win->player_sp[0].img = mlx_xpm_file_to_image(win->mlx, PP1,
			&(win->player_sp[0].width), &(win->player_sp[0].height));
	win->player_sp[1].img = mlx_xpm_file_to_image(win->mlx, PP2,
			&(win->player_sp[1].width), &(win->player_sp[1].height));
	win->player_sp[2].img = mlx_xpm_file_to_image(win->mlx, PP3,
			&(win->player_sp[2].width), &(win->player_sp[2].height));
	win->player_sp[3].img = mlx_xpm_file_to_image(win->mlx, PP3,
			&(win->player_sp[3].width), &(win->player_sp[3].height));
}

void	load_terrain(w_vars *win)
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
}

void	sprite_selection(w_vars *win, int i, int j)
{
	if (win->map->map_mx[i][j] == 'P')
		mlx_put_image_to_window(win->mlx, win->win,
			win->player_sp[win->frame].img,
			j * win->player_sp[win->frame].width,
			i * win->player_sp[win->frame].height);
	if (win->map->map_mx[i][j] == 'V')
		mlx_put_image_to_window(win->mlx, win->win,
			win->enemy_sp[win->frame].img, j * win->enemy_sp[win->frame].width,
			i * win->enemy_sp[win->frame].height);
}

int	sprite_animation(w_vars *win)
{
	int	i;
	int	j;

	render_move(win);
	if (win->frame < PLAYER - 1)
		win->frame += 1;
	else
		win->frame = 0;
	i = -1;
	while (++i <= win->map->row)
	{
		j = -1;
		while (++j <= win->map->col)
		{
			sprite_selection(win, i, j);
			usleep(250);
		}
	}
	return (0);
}
