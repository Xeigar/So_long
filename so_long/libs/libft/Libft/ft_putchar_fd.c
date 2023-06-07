/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:40:14 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 14:40:19 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <fcntl.h>
int main(void)
{
	int	fd;

	fd = open("test", O_RDWR | O_CREAT, 0666);
	ft_putchar_fd('c', fd);
	close(fd);
	return 0;
}*/