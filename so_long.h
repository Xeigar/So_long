/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:04:44 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/19 19:35:51 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"

#	define SIZE 32
#	define SPRITES 1
#	define PW	"./Images and stuff/Walls/wall_righ.xpm"
#	define PP
#	define PC
#	define PE
#	define PB 

typedef struct s_struct
{
	int	prev_size;
	int	p;
	int	c;
	int	e;
	int free;
}	t_struct;

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

typedef struct s_map
{
	char *map;
	int col;
	int row;
}	t_map;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}	t_sprite;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_sprite	*sp;
	t_map	*map;
}				w_vars;


void	checker_initialize(t_struct *checker);
void	error_call(char *message);
void	wall_checker(w_vars *win, int wid);
void	map_checker(w_vars *win, t_struct *checker);

#endif