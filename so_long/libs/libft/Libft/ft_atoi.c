/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:30:34 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:19:52 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg *= (-1);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		i = i * 10 + (*nptr - 48);
		nptr++;
	}
	return (i * neg);
}

/*
#include <stdio.h>
int main (void)
{
	char	*str = "	 ---+-+-++2147483648a2b567";
	printf("%i\n", ft_atoi(str));
	return (0);
}
*/
