/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:39:17 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:58:34 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill(char *t_dest, char *t_src, size_t n)
{
	size_t	i;

	i = 0;
	if (t_dest > t_src)
	{
		while (i < n)
		{
			t_dest[n - i - 1] = t_src[n - i - 1];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			t_dest[i] = t_src[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*t_dest;
	char	*t_src;

	if (!dest && !src)
		return (NULL);
	t_dest = (char *)dest;
	t_src = (char *)src;
	fill(t_dest, t_src, n);
	return (t_dest);
}

/*
#include <stdio.h>
int main(void)
{
	char src[50] = "Hello how are you";
	char dest[50];
	ft_memmove(dest, src, 5);
	printf("%s\n", dest);
	return (0);
}
*/
