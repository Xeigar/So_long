/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:48:26 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/04 19:19:41 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	w_vars		win;
	t_map		map;
	t_struct	checker;
	t_sprite	*sp;

	ft_bzero(&win, sizeof(w_vars));
	win.map = &map;
	win.map->map_mx = NULL;
	win.checker = &checker;
	ft_bzero(&sp, sizeof(t_sprite) * SPRITES);
	win.sp = sp;
	map_project(argc, argv, &win, win.checker);
	lauch_game(&win);
	get_assets(&win);
	build_map(&win);
	ft_bzero(&win.player_next, sizeof(t_point));
	mlx_hook(win.win, 2, (1L << 0), get_key, &win);
	mlx_hook (win.win, 17, (1L << 17), quit_game, &win);
	mlx_loop_hook(win.mlx, render_move, &win);
	mlx_loop(win.mlx);
	return (0);
}
