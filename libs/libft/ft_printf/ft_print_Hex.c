/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_Hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:33:48 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/27 22:33:48 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned int i, t_struct *ptr)
{
	if (i >= 16)
	{
		ft_puthex(i / 16, ptr);
		ft_puthex(i % 16, ptr);
	}
	else
	{
		if (i <= 9)
			ft_putchar_fd((i + 48), 1);
		else
			ft_putchar_fd((i - 10 + 'A'), 1);
		ptr->len += 1;
	}
}

void	ft_print_bhex(t_struct *ptr)
{
	unsigned int	i;

	i = va_arg(ptr->arg, unsigned int);
	ft_puthex(i, ptr);
}
