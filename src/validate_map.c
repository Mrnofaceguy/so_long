/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:00:00 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/03 15:17:27 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_unreachable(char **tmp, t_map *m, char **err)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->h)
	{
		j = 0;
		while (j < m->w)
		{
			if ((m->grid[i][j] == 'C' || m->grid[i][j] == 'E')
				&& tmp[i][j] != 'V')
			{
				*err = "no valid path";
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	free_tmp(char **tmp, int h)
{
	int		k;

	k = 0;
	while (k < h)
		free(tmp[k++]);
	free(tmp);
}

int	alloc_rows(char ***tmp, t_map *m)
{
	int		i;

	*tmp = (char **)sl_calloc(m->h, sizeof(char *));
	if (!*tmp)
		return (0);
	i = 0;
	while (i < m->h)
	{
		(*tmp)[i] = (char *)sl_calloc(m->w + 1, 1);
		if (!(*tmp)[i])
		{
			while (--i >= 0)
				free((*tmp)[i]);
			free(*tmp);
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_map(t_map *m, char **err)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->h)
	{
		j = 0;
		while (j < m->w)
		{
			if (m->grid[i][j] != '0' && m->grid[i][j] != '1' &&
				m->grid[i][j] != 'C' && m->grid[i][j] != 'E' &&
				m->grid[i][j] != 'P')
			{
				*err = "invalid character";
				return (0);
			}
			j++;
		}
		i++;
	}
	if (!scan_map(m, err))
		return (0);
	return (check_reachable(m, err));
}

void	ff(char **g, int x, int y, t_map *m)
{
	if (x < 0 || y < 0 || x >= m->w || y >= m->h)
		return ;
	if (g[y][x] == '1' || g[y][x] == 'V')
		return ;
	g[y][x] = 'V';
	ff(g, x + 1, y, m);
	ff(g, x - 1, y, m);
	ff(g, x, y + 1, m);
	ff(g, x, y - 1, m);
}
