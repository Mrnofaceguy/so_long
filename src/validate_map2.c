/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:42:23 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/12 10:03:15 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_grid(char **dst, t_map *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->h)
	{
		j = 0;
		while (j < m->w)
		{
			dst[i][j] = m->grid[i][j];
			j++;
		}
		dst[i][j] = 0;
		i++;
	}
}

int	check_reachable(t_map *m, char **err)
{
	char	**tmp;

	if (!alloc_rows(&tmp, m))
		return (0);
	copy_grid(tmp, m);
	ff(tmp, m->player_x, m->player_y, m);
	if (!check_unreachable(tmp, m, err))
	{
		free_tmp(tmp, m->h);
		return (0);
	}
	free_tmp(tmp, m->h);
	return (1);
}

void	init_counts(t_map *m, int *player_count, int *exit_count)
{
	*player_count = 0;
	*exit_count = 0;
	m->n_collect = 0;
	m->player_x = -1;
	m->player_y = -1;
}

int	count_elements(t_map *m, int *player_count, int *exit_count)
{
	int	i;
	int	j;

	init_counts(m, player_count, exit_count);
	i = 0;
	while (i < m->h)
	{
		j = 0;
		while (j < m->w)
		{
			if (m->grid[i][j] == 'P')
			{
				(*player_count)++;
				m->player_x = j;
				m->player_y = i;
			}
			else if (m->grid[i][j] == 'C')
				m->n_collect++;
			else if (m->grid[i][j] == 'E')
				(*exit_count)++;
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_counts(int player_count, int exit_count, int n_collect, char **err)
{
	if (player_count != 1)
	{
		*err = "invalid number of players";
		return (0);
	}
	if (n_collect == 0)
	{
		*err = "no collectibles";
		return (0);
	}
	if (exit_count == 0)
	{
		*err = "no exit";
		return (0);
	}
	if (exit_count > 1)
	{
		*err = "multiple exits detected";
		return (0);
	}
	return (1);
}
