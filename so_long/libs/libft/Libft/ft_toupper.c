/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:01:41 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 15:02:03 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	int	i;

	i = 0;
	if (c >= 'a' && c <= 'z')
	{
		i = c - ('a' - 'A');
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
	printf("%c\n%c\n", ft_toupper(a), ft_toupper(b));
	return 0;
}*/