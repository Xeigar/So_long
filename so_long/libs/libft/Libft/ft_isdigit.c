/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:32:53 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 14:33:05 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_isdigit(a));
	printf("%d\n", ft_isdigit(5));
	printf("%d\n", ft_isdigit(*));
	return 0;
}
*/