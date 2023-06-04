/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:39:02 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:33:34 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *) dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
	char src[50] = "mahmudulhasanjony";
	char dest[50];
	char *ret;

	ret = ft_memcpy(dest, src, 9);
	printf("%s", ret);
	return (0);
}
*/