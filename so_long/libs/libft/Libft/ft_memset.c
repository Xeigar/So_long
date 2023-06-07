/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:39:59 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:32:44 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
int main(void)
{
	char str[50] = "Hello how are you";
	printf("%s\n", str);
	ft_memset(str, '$', 5);
	printf("%s\n", str);
	return (0);
}
*/
