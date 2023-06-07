/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:48:26 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/04 18:21:43 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	w_vars		win;
	t_map		map;
	t_struct	checker;

	ft_bzero(&win, sizeof(w_vars));
	win.map = &map;
	win.map->map_mx = NULL;
	win.checker = &checker;
	map_project(argc, argv, &win, win.checker);
	lauch_game(&win);
	get_assets(&win);
	build_map(&win);
	ft_bzero(&win.player_next, sizeof(t_point));
	mlx_hook(win.win, 2, (1L << 0), get_key, &win);
	mlx_hook (win.win, 17, (1L << 17), quit_game, &win);
	mlx_loop_hook(win.mlx, sprite_animation, &win);
	mlx_loop(win.mlx);
	return (0);
}
