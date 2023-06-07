/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:56:40 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:14:50 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
		return ((char *) big);
	j = 0;
	while (big[j] && j < len)
	{
		i = 0;
		while (big[j + i] == little[i]
			&& j + i < len && little[i])
			i++;
		if (little[i] == '\0')
			return ((char *)(big + j));
		j++;
	}
	return (NULL);
}

/*int main()
{
		char *haystack = "MZIRIBMZIRIBMZE123";
		char *needle = "MZIRIBMZE";
		size_t n = 9;
		printf("%p\n", NULL);
		printf("%s\n", ft_strnstr(haystack, needle, n));
		return 0;
}*/
