/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:45:56 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/04/11 19:03:51 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/*
char add(unsigned int i, char s)
{
	(void) i;
	s = s +1;
	return (s);
}
int main(void)
{
	printf("%s\n", ft_strmapi("Hello", &add));
	return 0;
}
*/