/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfilipe- <bfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:01:24 by bfilipe-          #+#    #+#             */
/*   Updated: 2025/09/03 15:02:56 by bfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	scan_map(t_map *m, char **err)
{
	int	player_count;
	int	exit_count;

	count_elements(m, &player_count, &exit_count);
	return (validate_counts(player_count, exit_count, m->n_collect, err));
}
