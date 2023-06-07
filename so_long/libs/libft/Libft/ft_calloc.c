/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:31:56 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:28:58 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	p = (char *)malloc(nmemb * size);
	if (p == NULL)
		return (0);
	ft_bzero (p, nmemb * size);
	return (p);
}

/*int main()
{	
		int size = 0;
		int *junk = 0;
		srand( time(0) );

		for (int i = 0; i < 1000; i++)
		{
				size = rand() % 160;
				junk = malloc(size * sizeof(int));
				for ( int j = 0; j < size; j++)
						junk[j] = rand();
				free(junk);
		}
		int *array;
		array = ft_calloc(0,sizeof(int));
		for(int i = 0; i < 1000; i++)
				printf("%d", array[i]);
		free(array);
		return 0;
}*/
