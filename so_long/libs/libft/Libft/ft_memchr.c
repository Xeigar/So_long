/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:38:21 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:32:17 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*sv;

	d = (unsigned char)c;
	sv = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(sv) == d)
			return ((void *)sv);
		sv++;
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_memchr("Hello how", 'h', 3));
	return 0;
}*/