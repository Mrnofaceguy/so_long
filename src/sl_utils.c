/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:00:00 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/03 12:33:14 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	sl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*sl_calloc(size_t n, size_t size)
{
	size_t	i;
	char	*p;

	p = (char *)malloc(n * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n * size)
		p[i++] = 0;
	return ((void *)p);
}

char	*sl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*o;

	if (!s1 && !s2)
		return (NULL);
	o = (char *)malloc(sl_strlen(s1) + sl_strlen(s2) + 1);
	if (!o)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		o[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		o[i + j] = s2[j];
		j++;
	}
	o[i + j] = 0;
	if (s1)
		free(s1);
	return (o);
}

void	sl_putendl(const char *s)
{
	if (!s)
		return ;
	write(1, s, sl_strlen(s));
	write(1, "\n", 1);
}

void	quit_error(const char *msg, t_game *g)
{
	(void)g;
	write(2, "Error\n", 6);
	if (msg)
	{
		write(2, msg, sl_strlen(msg));
		write(2, "\n", 1);
	}
	exit(1);
}
