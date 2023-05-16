/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:07:13 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/16 16:14:37 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker_initialize(t_struct *checker)
{
	checker->prev_size = 0;
	checker->p = 0 ;
	checker->c = 0;
	checker->e = 0;
}

void	error_call(char *message)
{
	perror(message);
	exit(1);
}

void	wall_checker(w_vars *win, int wid)
{
	int	len;
	int	line;
	int	colu;
	int	i;

	len = 0;
	while(win->map[len] != '\n')
		len++;
	line = len; //13
	colu = (wid - 1)/ (1 + len);//4
	i = 0;
	wid = 0;
	while (wid <= colu)
	{
		len = 0;
		while (len <= line)
		{
			if ((wid == 0 || wid == colu) || (len == 0 || len == line - 1))
				if (win->map[i] != '1' && win->map[i] != '\n')
					error_call("Error\nMissing wall");
			len++;
			i++;
		}
		wid++;
	}
}

/*Missing the verification of valid path FALTA VERIFICAR SE SE COLOCA OUTRO CHARACTER*/
void	map_checker(w_vars *win, t_struct *checker)
{
	int	i;

	i = 0;
	while(win->map[i])
	{
		if (win->map[i] == 'P')
			checker->p += 1;
		if (win->map[i] == 'E')
			checker->e += 1;
		if (win->map[i] == 'C')
			checker->c += 1;
		if (win->map[i] == '0')
			checker->free += 1;
		i++;
	}
	if (checker->p != 1)
		error_call("Error\nOn starting position");
	if (checker->free <= 0)
		error_call("Error\nNo free space");
	if (checker->c <= 0)
		error_call("Error\nNo colectibles");
	if (checker->e != 1)
		error_call("Error\nOn exit");
	printf("%s", win->map);/*used just to visualize the map*/
	wall_checker(win, i);
}
