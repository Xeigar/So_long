/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:36:50 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 14:37:00 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

/*
#include <stdio.h>
int main(void)
{
	t_list *arr;
	char *a = "hello";
	arr = ft_lstnew(a);
	arr->next = ft_lstnew("Hello1");
	printf("%s\n", ft_lstlast(arr));
	return 0;
}
*/