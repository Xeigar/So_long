/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:17:34 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/01 13:57:07 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*initialise_tab(t_struct *tab)
{
	tab->wdt = 0;
	tab->car = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->plus = 0;
	tab->len = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}

int	flag_check(char i)
{
	int		j;
	char	*arr;

	arr = "+- #0.";
	j = 0;
	while (arr[j])
	{
		if (i == arr[j] || (i >= '1' && i <= '9'))
			return (1);
		j++;
	}
	return (0);
}

void	flag_count(int i, const char *txt, t_struct *ptr)
{
	while (flag_check(txt[i]) == 1)
	{
		if (txt[i++] == '#')
			ptr->car = 1;
		if (txt[i++] == '-')
			ptr->dash = 1;
		if (txt[i++] == '0')
			ptr->zero = 1;
		if (txt[i++] == '+')
			ptr->plus = 1;
		if (txt[i++] == '.')
			ptr->pnt = 1;
		if (txt[i++] == ' ')
			ptr->sp = 1;
		if (txt[i] > '0' && txt[i] <= '9')
		{
			ptr->wdt = ft_atoi(txt + i);
			while (txt[i] > '0' && txt[i] <= '9')
				i++;
		}
	}
	return ;
}

int	checker(t_struct *ptr, const char *txt, int i)
{
	flag_count(i, txt, ptr);
	if (txt[i] == 'c')
		ft_print_char(ptr);
	else if (txt[i] == 's')
		ft_print_str(ptr);
	else if (txt[i] == 'p')
		ft_print_void(ptr);
	else if (txt[i] == 'i' || txt[i] == 'd')
		ft_print_int(ptr);
	else if (txt[i] == 'u')
		ft_print_usgn(ptr);
	else if (txt[i] == 'x')
		ft_print_hex(ptr);
	else if (txt[i] == 'X')
		ft_print_bhex(ptr);
	else if (txt[i] == '%')
		ft_print_per(ptr);
	else if (!txt[i])
		return (0);
	else
	{
		ptr->len += write(1, "%", 1);
		i--;
	}
	return (i);
}

int	ft_printf(const char *txt, ...)
{
	int			i;
	int			len;
	t_struct	*ptr;

	ptr = (t_struct *)malloc(sizeof(*ptr));
	if (!ptr)
		return (-1);
	va_start(ptr->arg, txt);
	len = 0;
	i = 0;
	initialise_tab(ptr);
	while (txt[i])
	{
		if (txt[i] == '%')
			i = checker(ptr, txt, i + 1);
		else
			len += write(1, &txt[i], 1);
		len += ptr->len;
		initialise_tab(ptr);
		i++;
	}
	va_end(ptr->arg);
	free (ptr);
	return (len);
}
