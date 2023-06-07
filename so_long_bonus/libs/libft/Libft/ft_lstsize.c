/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:37:58 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:29:39 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*a;
	int		i;

	a = lst;
	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

/*
#include <stdio.h>
int main(void)
{
	t_list *arr;
	char *a = "hello";
	arr = ft_lstnew(a);
	arr->next = ft_lstnew(a);
	printf("%i\n", ft_lstsize(arr));
	return 0;
}
*/