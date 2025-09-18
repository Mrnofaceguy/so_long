/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:00:00 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/18 16:29:40 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_map
{
	char	**grid;
	int		w;
	int		h;
	int		player_x;
	int		player_y;
	int		n_collect;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	wall;
	t_img	floor;
	t_img	exit;
	t_img	player;
	t_img	collect;
	t_map	map;
	int		moves;
	int		collected;
}	t_game;

int		load_map(const char *path, t_map *map);
int		validate_map(t_map *m, char **err);
void	free_map(t_map *map);

t_img	load_tex(void *mlx, const char *path);
void	put_img(t_game *g, t_img img, int x, int y);
int		can_walk(t_game *g, int x, int y);
void	step_into(t_game *g, int nx, int ny);

void	copy_grid(char **dst, t_map *m);
int		check_reachable(t_map *m, char **err);

int		init_game(t_game *g);
int		render_all(t_game *g);
int		handle_key(int keycode, t_game *g);
int		close_win(t_game *g);
void	cleanup_game(t_game *g);

size_t	sl_strlen(const char *s);
void	*sl_calloc(size_t n, size_t size);
char	*sl_strjoin(char *s1, char *s2);
char	**sl_split_lines(char *buf, int *h, int *w);
void	sl_putendl(const char *s);
void	quit_error(const char *msg, t_game *g);
int		check_unreachable(char **tmp, t_map *m, char **err);
void	free_tmp(char **tmp, int h);
int		alloc_rows(char ***tmp, t_map *m);
void	ff(char **g, int x, int y, t_map *m);
int		scan_map(t_map *m, char **err);
int		validate_counts(int p_count, int e_count, int n_collect, char **err);
int		count_elements(t_map *m, int *player_count, int *exit_count);

int		ft_printf(const char *fmt, ...);

#endif
