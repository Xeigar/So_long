/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:55:29 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:24:21 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				size;
	char			*tab;
	int unsigned	i;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	tab = (char *)malloc(sizeof(*tab) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

/*
char add(unsigned int i, char s)
{
	(void) i;
	s = s +1;
	return (s);
}
int main(void)
{
	printf("%s\n", ft_strmapi("Hello", &add));
	return 0;
}
*/