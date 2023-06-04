/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:33:08 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:40:15 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_isprint(a));
	printf("%d\n", ft_isprint( ));
	printf("%d\n", ft_isprint(	));
	return 0;
}
*/