/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/23 15:44:19 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	is_wall(t_data *data, float x, float y)
{
	int	m;
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	m = (BLOCK_SIZE + 6) / (2 * SIZE_PLAYER) - 1;
	if (x - m < 0 || y - m < 0)
		return (1);
	x0 = (int)((x - m) / BLOCK_SIZE);
	x1 = (int)((x + m) / BLOCK_SIZE);
	y0 = (int)((y - m) / BLOCK_SIZE);
	y1 = (int)((y + m) / BLOCK_SIZE);
	if (cell_blocked(data, x0, y0) || cell_blocked(data, x1, y0))
		return (1);
	if (cell_blocked(data, x0, y1) || cell_blocked(data, x1, y1))
		return (1);
	return (0);
}

static int	sign_axis(int pos, int neg)
{
	if (pos && !neg)
		return (1);
	if (neg && !pos)
		return (-1);
	return (0);
}

static void	apply_move(t_data *data, float nx, float ny)
{
	if ((nx != data->player.pos.x || ny != data->player.pos.y)
		&& !is_wall(data, nx, data->player.pos.y))
		data->player.pos.x = nx;
	if ((nx != data->player.pos.x || ny != data->player.pos.y)
		&& !is_wall(data, data->player.pos.x, ny))
		data->player.pos.y = ny;
}

void	move_player(t_data *data, float dir_x, float dir_y, int speed)
{
	float	nx;
	float	ny;
	int		vert;
	int		horiz;

	nx = data->player.pos.x;
	ny = data->player.pos.y;
	vert = sign_axis(data->player.move_up, data->player.move_down);
	horiz = sign_axis(data->player.move_left, data->player.move_right);
	nx += dir_y * speed * vert - dir_x * speed * horiz;
	ny += dir_x * speed * vert + dir_y * speed * horiz;
	apply_move(data, nx, ny);
}
