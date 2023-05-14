/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:08:13 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/14 19:51:13 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker_initialize(t_struct *checker)
{
	chercker->size = 0;
	checker->p = 0 ;
	checker->c = 0;
	checker->e =0;
}

void	map_checker(char *map)
{
	int			fd;
	int			prev_size;
	t_struct	checker;
	char		*line;

	fd = open(map, O_RDONLY);
	if (fd = -1)
		perror("Error opening file");
	checker_initialize(&checker);
	line = get_next_line(fd);
	prev_size = ft_strlen(line);
	while (line)
	{
		checker.size = ft_strlen(line);
		if (checker.size != prev_size)
			perror("Lines are not same size");
		if (ft_strchr(line, 'p'))
			checker.p += 1;
		if (checker.p != 1)
			perror("More than one starting position");
		if (ft_strchr(line, 'c'))
			checker.c += 1;
		if (checker.c <= 0)
			perror("No colectibles");
		if (ft_strchr(line, 'e'))
			checker.e += 1;
		if (checker.e != 1)
			perror("More than one exit");
		line = get_next_line(fd);
	}
	close (fd);
}

void	param_checker(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
		perror("Wrong number of maps");
	map_checker(argv[2]);
}

int	main (int argc, char **argv)
{
	param_checker(argc, argv);
	return (0);
}