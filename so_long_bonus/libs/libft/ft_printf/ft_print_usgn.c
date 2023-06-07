/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usgn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:58:36 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/28 18:27:33 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	base(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size ++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*ft_uitoa(unsigned int n)
{
	char				*tab;
	unsigned int		size;
	unsigned long int	i;

	i = n;
	size = base(n);
	tab = (char *)malloc(sizeof(*tab) * (size + 1));
	if (!tab)
		return (NULL);
	tab[size] = '\0';
	if (i == 0)
		tab[0] = (n + 48);
	while (i != 0)
	{
		tab[size - 1] = i % 10 + 48;
		i = i / 10;
		size--;
	}
	return (tab);
}

void	ft_print_usgn(t_struct *ptr)
{
	unsigned int	i;
	char			*p;

	i = va_arg(ptr->arg, unsigned int);
	p = ft_uitoa(i);
	ft_putstr_fd(p, 1);
	ptr->len = ft_strlen(p);
	free (p);
}
