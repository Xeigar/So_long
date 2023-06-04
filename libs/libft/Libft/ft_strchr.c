/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:45:22 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 14:45:23 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	l;

	i = ft_strlen(s);
	l = 0;
	while (l <= i)
	{
		if (s[l] == (char)c)
			return ((char *)(s + l));
		l++;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%p\n", ft_strchr("teste", 1024));
	printf("%p\n", strchr("teste", 1024));
	return 0;
}*/
