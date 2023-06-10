/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:39:56 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/10 15:44:20 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_call(char *message, t_vars *win)
{
	perror(message);
	exit_game(win);
	exit(1);
}

void	clean_map(t_vars *win)
{
	int	i;

	if (!win->map->map_mx)
		return ;
	i = -1;
	while (++i <= win->map->row)
		free(win->map->map_mx[i]);
	free(win->map->map_mx);
}

void	clean_sprites(t_vars *win, t_sprite *arr, int size)
{
	int	i;

	i = 0;
	if (arr[i].img)
	{
		while (i < size)
		{
			mlx_destroy_image(win->mlx, arr[i].img);
			i++;
		}
	}
	free (arr);
}

void	exit_game(t_vars *win)
{
	if (!win)
		return ;
	if (win->sp)
		clean_sprites(win, win->sp, SPRITES);
	if (win->player_sp)
		clean_sprites(win, win->player_sp, PLAYER);
	if (win->enemy_sp)
		clean_sprites(win, win->enemy_sp, ENEMY);
	if (win->map->map_mx)
		clean_map(win);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
		mlx_destroy_display(win->mlx);
	free(win->mlx);
}

int	quit_game(t_vars *win)
{
	exit_game(win);
	exit(EXIT_SUCCESS);
}
