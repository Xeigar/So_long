/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:58:50 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/28 17:25:19 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_mem(unsigned long long int i, t_struct *ptr)
{
	if (i >= 16)
	{
		ft_put_mem(i / 16, ptr);
		ft_put_mem(i % 16, ptr);
	}
	else
	{
		if (i <= 9)
			ft_putchar_fd((i + '0'), 1);
		else
			ft_putchar_fd((i - 10 + 'a'), 1);
		ptr->len += 1;
	}
}

void	ft_print_void(t_struct *ptr)
{
	unsigned long long int	i;

	i = va_arg(ptr->arg, unsigned long long int);
	if (i == 0)
	{
		ft_putstr_fd("(nil)", 1);
		ptr->len += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ptr->len += 2;
		ft_put_mem(i, ptr);
	}
}
