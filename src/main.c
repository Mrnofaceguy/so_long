/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:00:00 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/18 16:05:50 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_ber(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (len < 4)
		return (0);
	return (s[len - 4] == '.' && s[len - 3] == 'b'
		&& s[len - 2] == 'e' && s[len - 1] == 'r');
}

int	main(int argc, char **argv)
{
	t_game	g;
	char	*err;

	err = NULL;
	if (argc != 2 || !has_ber(argv[1]))
		quit_error("usage: ./so_long maps/map.ber", NULL);
	if (!load_map(argv[1], &g.map))
		quit_error("invalid or unreadable map", NULL);
	ft_printf("Path: %s\n", argv[1]);
	if (!validate_map(&g.map, &err))
	{
		free_map(&g.map);
		quit_error(err, NULL);
	}
	if (!init_game(&g))
		quit_error("mlx init failed or textures missing", NULL);
	render_all(&g);
	mlx_hook(g.win, 2, 1L << 0, handle_key, &g);
	mlx_hook(g.win, 17, 0, close_win, &g);
	mlx_loop(g.mlx);
	free_map(&g.map);
	return (0);
}
