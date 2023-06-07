/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:33:19 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:18:49 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	base(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		size;
	long	i;

	i = n;
	size = base(n);
	tab = (char *)malloc(sizeof(*tab) * (size + 1));
	if (!tab)
		return (NULL);
	if (i < 0)
	{		
		tab[0] = '-';
		i = -i;
	}
	tab[size] = '\0';
	if (i == 0)
		tab[0] = (n + 48);
	while (i != 0)
	{
		tab[size - 1] = i % 10 + 48;
		i = i / 10;
		size--;
	}
	return (tab);
}

/*int main(void)
{
	printf("%s\n", ft_itoa(123156));
	return (0);
}*/