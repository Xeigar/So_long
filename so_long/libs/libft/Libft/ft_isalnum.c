/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:32:14 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 14:32:22 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_isalnum(a));
	printf("%d\n", ft_isalnum(5));
	printf("%d\n", ft_isalnum(*));
	return 0;
}
*/