/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:16:33 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/28 15:37:26 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_struct
{
	va_list	arg;
	int		wdt;
	int		car;
	int		zero;
	int		pnt;
	int		dash;
	int		plus;
	int		perc;
	int		sp;
	int		len;
}	t_struct;

void	ft_print_char(t_struct *ptr);
void	ft_print_str(t_struct *ptr);
void	ft_print_int(t_struct *ptr);
void	ft_print_per(t_struct *ptr);
void	ft_print_hex(t_struct *ptr);
void	ft_print_bhex(t_struct *ptr);
void	ft_print_void(t_struct *ptr);
void	ft_print_usgn(t_struct *ptr);
int		ft_printf(const char *txt, ...);

#endif