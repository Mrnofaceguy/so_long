/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:27:55 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/18 16:38:05 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_game(t_game *g)
{
	/* Free all the loaded images */
	if (g->wall.ptr)
		mlx_destroy_image(g->mlx, g->wall.ptr);
	if (g->floor.ptr)
		mlx_destroy_image(g->mlx, g->floor.ptr);
	if (g->exit.ptr)
		mlx_destroy_image(g->mlx, g->exit.ptr);
	if (g->player.ptr)
		mlx_destroy_image(g->mlx, g->player.ptr);
	if (g->collect.ptr)
		mlx_destroy_image(g->mlx, g->collect.ptr);
	
	/* Destroy window before destroying display */
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	
	/* Free map after MLX cleanup */
	free_map(&g->map);
	
	/* Destroy display and free MLX last */
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}