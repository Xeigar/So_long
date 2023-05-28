/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:04:44 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/28 17:14:33 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"

#	define SIZE		32
#	define SPRITES	5
#	define PW		"./sprites/walls/wall_right.xpm"
#	define PP		"./sprites/Evil/evil.xpm"
#	define PC		"./sprites/coin/coin.xpm"
#	define PE		"./sprites/exit/close.xpm"
#	define PF		"./sprites/free/free.xpm"
#	define PO		"./sprites/exit/open.xpm"

typedef struct s_struct
{
	int	prev_size;
	int	p;
	int	p_ck;
	int	c;
	int	c_ck;
	int	e;
	int	e_ck;
	int	unk;
}	t_struct;

typedef enum e_index
{
	W1 = 0,
	F1 = 1,
	C1 = 2,
	E1 = 3,
	P1 = 4,
}		t_id;

typedef enum e_button
{
	ESC		= 65307,
	W		= 119,
	A		= 97,
	S		= 115,
	D		= 100,
	UP		= 65362,
	DOWN	= 65364,
	LEFT	= 65361,
	RIGHT	= 65363,
}		t_button;

typedef	struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**map_mx;
	size_t		col;
	size_t		row;
}	t_map;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}	t_sprite;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_sprite	*sp;
	t_map		*map;
	t_point		player;
	t_point		player_next;
	t_struct	*checker;
}				w_vars;


int		main(int argc, char **argv);
int		render_move(w_vars *win);
int		get_sprite(t_point	a, w_vars *win);
void	move_player(w_vars *win, t_map *map);
int		get_key(int keycode, w_vars *win);
int		quit_game(w_vars *win);
void	exit_game(w_vars *win);
void	clean_sprites(w_vars *win);
void	clean_map(w_vars *win);
void	lauch_game(w_vars *win);
void	build_map(w_vars *win);
void	place(w_vars *win, t_point pos);
void	get_assets(w_vars *win);
void	error_call(char *message, w_vars *win);
int		get_rows(char *file);
char	**matrix_generator(int fd, w_vars *win, char *line);
void	get_map(int argc, char **argv, w_vars *win, t_struct *checker);
void	wall_checker(w_vars *win);
void	flood_fill(char **map, t_point origin, t_struct *checker);
char	**matrix_duplicator(w_vars *win);
void	path_check(w_vars *win, t_struct *checker);
void	map_checker(w_vars *win, t_struct *checker);
void	char_check(w_vars *win, t_struct *checker);
void	map_project(int argc, char **argv, w_vars *win, t_struct *checker);

#endif