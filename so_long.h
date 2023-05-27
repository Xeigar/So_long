/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:04:44 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/27 17:37:52 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"

#	define SIZE 32
#	define SPRITES 5
#	define PW "./sprites/walls/wall_right.xpm"
#	define PP "./sprites/Evil/test.xpm"
#	define PC "./sprites/coin/coin.xpm"
#	define PE "./sprites/exit/close.xpm"
#	define PF "./sprites/free/free.xpm"

typedef struct s_struct
{
	int	prev_size;
	int	p;
	int	p_ck;
	int	c;
	int	c_ck;
	int	e;
	int	e_ck;
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

typedef struct s_data
{
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
    int		h;
	int		w;
	int		endian;
}	img_data;

typedef	struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	*map_txt;
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

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_sprite	*sp;
	t_map		*map;
	t_point		player;
	t_point		player_next;
	t_struct	*checker;
}				w_vars;


void	checker_initialize(t_struct *checker);
void	error_call(char *message);
void	wall_checker(w_vars *win, int wid);
void	map_checker(w_vars *win, t_struct *checker);

#endif