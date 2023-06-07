/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:32:28 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 18:56:56 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_isalpha(a));
	printf("%d\n", ft_isalpha(5));
	printf("%d\n", ft_isalpha(*));
	return 0;
}
*/