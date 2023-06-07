/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:37:03 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 14:37:38 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	nl = NULL;
	current = NULL;
	while (lst)
	{
		nl = ft_lstnew(f(lst->content));
		if (!nl)
		{
			ft_lstclear(&nl, del);
			return (NULL);
		}
		ft_lstadd_back(&current, nl);
		lst = lst->next;
	}
	return (current);
}
