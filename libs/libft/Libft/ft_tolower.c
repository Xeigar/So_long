/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:01:26 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:35:50 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	int	i;

	i = 0;
	if (c >= 'A' && c <= 'Z')
	{
		i = c + ('a' - 'A');
		return (i);
	}
	return (c);
}

/*
#include <stdio.h>
int main(void)
{
	char a;
	char b;

	a = 'A';
	b = 'b';
	printf("%c\n%c\n", ft_tolower(a), ft_tolower(b));
	return 0;
}*/