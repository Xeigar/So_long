/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:54:47 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 14:55:01 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(src);
	if (size == 0)
		return (n);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (n);
}

/*int main (void)
{
	char *src="bleh bleh";
	char dest[10];
	ft_strlcpy(dest, src, 5);
	printf("%s \n", dest);
	printf("%i \n", ft_strlcpy(dest, src, 8));
	return 0;
}*/
