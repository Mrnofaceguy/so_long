/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:00:00 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/01 14:36:20 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (0);
	g->win = mlx_new_window(g->mlx, g->map.w * 32, g->map.h * 32, "so_long");
	g->wall = load_tex(g->mlx, "textures/wall.xpm");
	g->floor = load_tex(g->mlx, "textures/floor.xpm");
	g->exit = load_tex(g->mlx, "textures/exit.xpm");
	g->player = load_tex(g->mlx, "textures/player.xpm");
	g->collect = load_tex(g->mlx, "textures/collect.xpm");
	g->moves = 0;
	g->collected = 0;
	return (g->win && g->wall.ptr && g->floor.ptr && g->exit.ptr
		&& g->player.ptr && g->collect.ptr);
}

int	render_all(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map.h)
	{
		x = 0;
		while (x < g->map.w)
		{
			put_img(g, g->floor, x, y);
			if (g->map.grid[y][x] == '1')
				put_img(g, g->wall, x, y);
			if (g->map.grid[y][x] == 'E')
				put_img(g, g->exit, x, y);
			if (g->map.grid[y][x] == 'C')
				put_img(g, g->collect, x, y);
			if (x == g->map.player_x && y == g->map.player_y)
				put_img(g, g->player, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	handle_key(int key, t_game *g)
{
	int	nx;
	int	ny;

	nx = g->map.player_x;
	ny = g->map.player_y;
	if (key == 65307)
		return (close_win(g));
	if (key == 119 || key == 65362)
		ny--;
	if (key == 115 || key == 65364)
		ny++;
	if (key == 97 || key == 65361)
		nx--;
	if (key == 100 || key == 65363)
		nx++;
	if (can_walk(g, nx, ny))
		step_into(g, nx, ny);
	return (0);
}

int	close_win(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	exit(0);
	return (0);
}
