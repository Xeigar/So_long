/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:45:28 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:21:08 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	p = (char *)malloc(sizeof(*p) * (size + 1));
	if (p == NULL)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*int main(void)
{
	char *arra = "Hello";
	
	printf("%s", ft_strdup(arra));
	
	return (0);
}*/