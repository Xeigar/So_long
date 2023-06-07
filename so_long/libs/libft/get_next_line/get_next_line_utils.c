/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:29:45 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/15 10:48:56 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	sizing(const char *txt)
{
	int	i;

	if (!txt)
		return (0);
	i = 0;
	while (txt[i])
		i++;
	return (i);
}

char	*strjoiner(char *s1, char *s2)
{
	char	*ret;
	char	*p;
	int		i;
	int		size;

	size = sizing(s2);
	if (s1)
		size += sizing(s1);
	p = (char *)malloc(sizeof(*p) * (size + 1));
	if (!p)
		return (NULL);
	ret = p;
	i = -1;
	while (s1 && s1[++i])
		*p++ = s1[i];
	while (s2 && *s2)
		*p++ = *s2++;
	*p = 0;
	free(s1);
	return (ret);
}

char	*find_nl(const char *txt)
{
	int	i;

	i = 0;
	if (!txt)
		return (NULL);
	while (txt[i])
	{
		if (txt[i] == '\n')
			return ("found");
		i++;
	}
	return (NULL);
}

char	*extraction(char *txt)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!*txt)
		return (NULL);
	while (txt[i] && txt[i] != '\n')
		i++;
	if (txt[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(*line) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = txt[j];
		j++;
	}
	line[i] = 0;
	return (line);
}

char	*removal(char *txt)
{
	char	*text;
	char	*ret;
	int		i;

	if (!*txt)
	{
		free(txt);
		return (NULL);
	}
	ret = txt;
	while (*txt && *txt != '\n')
		txt++;
	if (*txt == '\n')
		txt++;
	i = 0;
	while (txt && txt[i])
		i++;
	text = (char *)malloc(sizeof(*text) * (i + 1));
	if (!text)
		return (NULL);
	text[i] = 0;
	while (i-- != 0)
		text[i] = txt[i];
	free(ret);
	return (text);
}
