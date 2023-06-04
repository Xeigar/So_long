/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:37:44 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 14:37:55 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(*p));
	if (!p)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}

/*
#include <stdio.h>
int main(void)
{
	t_list *arr;
	char *a = "Hello";
	arr = ft_lstnew(a);
	printf("%s\n", (char *)arr->content);
	return 0;
}
*/