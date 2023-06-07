/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:32:43 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 14:32:49 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (0 <= c && c < 128)
		return (1);
	return (0);
}

/*
#include <stdio.h>
int main
{
	printf("%d\n", ft_isascii(a));
	printf("%d\n", ft_isascii(5));
	printf("%d\n", ft_isascii(134));
	return 0;
}
*/