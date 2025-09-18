/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:00:00 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/03 14:44:16 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*append_chunk(char *out, char *buf, int n)
{
	char	*chunk;
	int		i;

	chunk = (char *)malloc(n + 1);
	if (!chunk)
	{
		free(out);
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		chunk[i] = buf[i];
		i++;
	}
	chunk[n] = 0;
	out = sl_strjoin(out, chunk);
	free(chunk);
	return (out);
}

static char	*read_all(int fd)
{
	char	buf[1024];
	int		n;
	char	*out;

	out = NULL;
	n = read(fd, buf, 1024);
	while (n > 0)
	{
		out = append_chunk(out, buf, n);
		if (!out)
			return (NULL);
		n = read(fd, buf, 1024);
	}
	return (out);
}

static int	check_walls(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->w)
	{
		if (m->grid[0][i] != '1' || m->grid[m->h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < m->h)
	{
		if (m->grid[i][0] != '1' || m->grid[i][m->w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	load_map(const char *path, t_map *map)
{
	int		fd;
	char	*buf;
	int		w;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = read_all(fd);
	close(fd);
	if (!buf)
		return (0);
	map->grid = sl_split_lines(buf, &map->h, &w);
	free(buf);
	map->w = w;
	if (w <= 0 || map->h <= 0)
		return (0);
	if (!check_walls(map))
		return (0);
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->grid)
		return ;
	while (i < map->h)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}
