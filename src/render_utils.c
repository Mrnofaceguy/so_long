/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:00:00 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/01 14:36:20 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Simple texture loader; img.ptr will be NULL on failure */
t_img	load_tex(void *mlx, const char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, (char *)path, &img.w, &img.h);
	return (img);
}

void	put_img(t_game *g, t_img img, int x, int y)
{
	if (img.ptr)
		mlx_put_image_to_window(g->mlx, g->win, img.ptr, x * 32, y * 32);
}

int	can_walk(t_game *g, int x, int y)
{
	return (x >= 0 && y >= 0 && x < g->map.w && y < g->map.h
		&& g->map.grid[y][x] != '1');
}

void	step_into(t_game *g, int nx, int ny)
{
	if (g->map.grid[ny][nx] == 'C')
	{
		g->map.grid[ny][nx] = '0';
		g->collected++;
	}
	if (g->map.grid[ny][nx] == 'E' && g->collected == g->map.n_collect)
	{
		ft_printf("Moves: %d\n", g->moves + 1);
		sl_putendl("You win!");
		cleanup_game(g);
		exit(0);
	}
	g->map.player_x = nx;
	g->map.player_y = ny;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
	render_all(g);
}
