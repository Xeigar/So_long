/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:39:56 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/04 19:11:32 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_call(char *message, w_vars *win)
{
	perror(message);
	exit_game(win);
	exit(1);
}

void	clean_map(w_vars *win)
{
	int	i;

	if (!win->map->map_mx)
		return ;
	i = -1;
	while (++i <= win->map->row)
		free(win->map->map_mx[i]);
	free(win->map->map_mx);
}

void	clean_sprites(w_vars *win)
{
	int	i;

	i = -1;
	while (++i < SPRITES)
		mlx_destroy_image(win->mlx, win->sp[i].img);
	free (win->sp);
}

void	exit_game(w_vars *win)
{
	if (!win)
		return ;
	if (win->map->map_mx)
		clean_map(win);
	if (win->sp)
		clean_sprites(win);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
		mlx_destroy_display(win->mlx);
	free(win->mlx);
}

int	quit_game(w_vars *win)
{
	exit_game(win);
	exit(EXIT_SUCCESS);
}
