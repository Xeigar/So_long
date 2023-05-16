/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:04:44 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/16 16:14:28 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"

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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		h;
	int		w;
	char	*map;
}				w_vars;


void	checker_initialize(t_struct *checker);
void	error_call(char *message);
void	wall_checker(w_vars *win, int wid);
void	map_checker(w_vars *win, t_struct *checker);

#endif