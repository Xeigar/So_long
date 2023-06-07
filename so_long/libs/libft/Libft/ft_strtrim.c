/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:57:25 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:39:07 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in(char const s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (0);
		i++;
	}
	return (1);
}

static void	fill(char *p, int start, int end, char const *s1)
{
	int	i;

	i = 0;
	if (end != 0)
	{		
		while (start <= end)
		{
			p[i] = s1[start];
			start++;
			i++;
		}
	}	
	p[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		size;
	char	*p;

	if (!s1)
		return (0);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (end != start && in(s1[end], set) == 0)
			end--;
	if (end == start)
		size = 1;
	else
	{
		while (start != end && in(s1[start], set) == 0)
			start++;
		size = end - start + 2;
	}
	p = (char *)malloc(sizeof(*p) * size);
	if (p == NULL)
		return (NULL);
	fill(p, start, end, s1);
	return (p);
}

/*
#include <stdio.h>
int main(void)
{
	char	*s1 = "   xxx   xxx";
	char	*s2 = " x";
	char	*s3 = ft_strtrim(s1, s2);

	printf("%s\n", ft_strtrim(s1, s2));
	printf("%d\n", ft_strlen(s3));
	return 0;
}
*/
