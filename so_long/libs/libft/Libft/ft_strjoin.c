/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:46:16 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:00:42 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(*p) * (size_s1 + size_s2 + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, (size_s1 + 1) * sizeof(char));
	ft_strlcat(p, s2, (size_s2 + size_s1 + 1) * sizeof(char));
	return (p);
}

/*int main()
{
		char *s1 = "my favorite animal is";
		char *s2 = "a";
		char *s3 = "the nyancat";
		char *temp = ft_strjoin(s1, s2);
		printf("%s\n", temp);
		printf("%s\n", ft_strjoin(temp, s3));
		return 0;
}*/
