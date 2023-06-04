/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:31:37 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:29:58 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		*(char *)s = 0;
		s++;
		i++;
	}
}

/*
#include <stdio.h>
int main (void)
{
	char str[50] = "Hello";
	size_t	n;
	n = 4;
	ft_bzero(str,n);
	printf("%s\n", str);
	return (0);
}*/