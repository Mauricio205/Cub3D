/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_scan_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	cell_free(t_data *data, int cx, int cy)
{
	if (cx < 0 || cy < 0 || cx >= data->count_line
		|| cy >= (int)ft_strlen(data->map[cx]))
		return (0);
	if (data->map[cx][cy] != '0' && data->map[cx][cy] != 'M')
		return (0);
	return (1);
}

int	random_cell_y(t_data *data, int cx)
{
	int	cells;

	cells = (int)ft_strlen(data->map[cx]);
	if (cells > 0)
		return (rand() % cells);
	return (0);
}

int	is_valid_spawn(t_data *data, int cell_x, int cell_y)
{
	int	px;
	int	py;
	int	dx;
	int	dy;
	int	i;

	if (!cell_free(data, cell_x, cell_y))
		return (0);
	px = data->player.pos.x / BLOCK_SIZE;
	py = data->player.pos.y / BLOCK_SIZE;
	dx = cell_x - px;
	dy = cell_y - py;
	if ((float)(dx * dx + dy * dy) < SPRITE_MIN_SPAWN_DIST
		* SPRITE_MIN_SPAWN_DIST)
		return (0);
	i = 0;
	while (i < data->sprite_count)
	{
		if (cell_x == (int)(data->sprites[i].x / BLOCK_SIZE)
			&& cell_y == (int)(data->sprites[i].y / BLOCK_SIZE))
			return (0);
		i++;
	}
	return (1);
}
