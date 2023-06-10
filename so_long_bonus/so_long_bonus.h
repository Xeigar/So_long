/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:04:44 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/06/10 15:43:54 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include "../so_long/libs/mlx_linux/mlx.h"
# include "../so_long/libs/libft/libft.h"

# define SIZE		32
# define SPRITES	4
# define PLAYER	4
# define ENEMY	4
# define PW		"./sprites/walls/wall_right.xpm"
# define PP1		"./sprites/Evil/evil_1.xpm"
# define PP2		"./sprites/Evil/evil_2.xpm"
# define PP3		"./sprites/Evil/evil_3.xpm"
# define PP4		"./sprites/Evil/evil_4.xpm"
# define PD1		"./sprites/villain/villain_8.xpm"
# define PD2		"./sprites/villain/villain_3.xpm"
# define PD3		"./sprites/villain/villain_4.xpm"
# define PD4		"./sprites/villain/villain_7.xpm"
# define PC		"./sprites/coin/coin.xpm"
# define PE		"./sprites/exit/close.xpm"
# define PF		"./sprites/free/free.xpm"
# define PO		"./sprites/exit/open.xpm"

typedef struct s_struct
{
	size_t	prev_size;
	int		p;
	int		p_ck;
	int		c;
	int		c_ck;
	int		e;
	int		e_ck;
	int		unk;
}	t_struct;

typedef enum e_index
{
	W1 = 0,
	F1 = 1,
	C1 = 2,
	E1 = 3,
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

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**map_mx;
	int		col;
	int		row;
}	t_map;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}	t_sprite;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			frame;
	int			moves;
	char		*move_print;
	t_sprite	*sp;
	t_sprite	*player_sp;
	t_sprite	*enemy_sp;
	t_map		*map;
	t_point		player;
	t_point		player_next;
	t_struct	*checker;
}				t_vars;

int		main(int argc, char **argv);
int		render_move(t_vars *win);
int		get_sprite(t_point	a, t_vars *win);
void	move_player(t_vars *win, t_map *map);
int		get_key(int keycode, t_vars *win);
int		quit_game(t_vars *win);
void	exit_game(t_vars *win);
void	clean_map(t_vars *win);
void	lauch_game(t_vars *win);
void	build_map(t_vars *win);
void	place(t_vars *win, t_point pos);
void	get_assets(t_vars *win);
void	error_call(char *message, t_vars *win);
int		get_rows(char *file);
char	**matrix_generator(int fd, t_vars *win, char *line);
void	get_map(int argc, char **argv, t_vars *win, t_struct *checker);
void	wall_checker(t_vars *win);
void	flood_fill(char **map, t_point origin, t_struct *checker);
char	**matrix_duplicator(t_vars *win);
void	path_check(t_vars *win, t_struct *checker);
void	map_checker(t_vars *win, t_struct *checker);
void	char_check(t_vars *win, t_struct *checker);
void	map_project(int argc, char **argv, t_vars *win, t_struct *checker);
int		sprite_animation(t_vars *win);
void	load_terrain(t_vars *win);
void	load_player(t_vars *win);
void	load_enemy(t_vars *win);
void	clean_sprites(t_vars *win, t_sprite *arr, int size);
void	temp_freer(char **arr);
void	line_freer(int fd, char *line, char **temp);
void	sprite_selection(t_vars *win, int i, int j);

#endif
