/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:50:58 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:05:46 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	det_len(size_t n, size_t dest_size, int src_size)
{
	if (n > dest_size)
		return (dest_size + src_size);
	else
		return (src_size + n);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;
	size_t	lenghts;

	if (size == 0 && !dst)
		return (0);
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	lenghts = det_len(size, dest_size, src_size);
	i = 0;
	while (src[i] && (dest_size + i + 1) < size)
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[dest_size + i] = '\0';
	return (lenghts);
}

/*int main()
{
                char dest[25];

                printf("%ld\n", ft_strlcat(NULL, "Hello", 0));
                printf("%s\n", dest);
                return 0;
}*/
