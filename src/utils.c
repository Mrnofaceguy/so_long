/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:00:00 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/18 16:38:39 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_line(char *buf, int *i, int *len)
{
	int		start;
	char	*line;

	start = *i;
	while (buf[*i] && buf[*i] != '\n')
		(*i)++;
	*len = *i - start;
	line = (char *)sl_calloc(*len + 1, 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, &buf[start], *len);
	if (buf[*i] == '\n')
		(*i)++;
	return (line);
}

static int	count_lines_buf(char *buf)
{
	int		i;
	int		lines;

	i = 0;
	lines = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			lines++;
		i++;
	}
	if (i && buf[i - 1] != '\n')
		lines++;
	return (lines);
}

static int	process_lines(char *buf, char ***out, int *w, int *h)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (buf[i])
	{
		(*out)[j] = read_line(buf, &i, &len);
		if (!(*out)[j])
		{
			while (--j >= 0)
				free((*out)[j]);
			free(*out);
			return (0);
		}
		if (*w == -1)
			*w = len;
		else if (len != *w)
		{
			*w = -1;
			while (j >= 0)
				free((*out)[j--]);
			free(*out);
			return (0);
		}
		j++;
	}
	if (!*h)
		*w = 0;
	return (1);
}

char	**sl_split_lines(char *buf, int *h, int *w)
{
	char	**out;

	*h = count_lines_buf(buf);
	out = (char **)sl_calloc(*h + 1, sizeof(char *));
	if (!out)
		return (NULL);
	*w = -1;
	if (!process_lines(buf, &out, w, h))
		return (NULL);
	return (out);
}
