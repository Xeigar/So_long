/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:43:12 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:37:39 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

int	word_length(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*duplic(const char *s, char c)
{
	char	*p;
	int		size;
	int		i;

	i = 0;
	size = word_length(s, c);
	p = (char *)malloc(sizeof(*p) * (size + 1));
	if (p == NULL)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	int		i;
	char	**tab;

	if (!s)
		return (NULL);
	wc = word_count(s, c);
	tab = (char **)malloc(sizeof(*tab) * (wc + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		while (*s == c)
			s++;
		if (*s != c)
		{
			tab[i] = duplic(s, c);
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	tab[wc] = NULL;
	return (tab);
}

/*int main()
{
		char **tab;
		int	i;

		tab = ft_split("Hello how are you   ", ' ');
		i = 0;
		while(tab[i])
		{
				printf("%s\n", tab[i]);
				i++;
		}
		return 0;
}*/
