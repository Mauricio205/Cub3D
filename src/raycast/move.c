/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:27:05 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall(t_data *data, float x, float y)
{
	int	margin;

	margin = (BLOCK_SIZE) / (2 * SIZE_PLAYER) - 1;
	if (x - margin < 0 || y - margin < 0)
		return (1);
	if (data->map[(int)(x - margin) / BLOCK_SIZE][(int)(y - margin)
		/ BLOCK_SIZE] == '1')
		return (1);
	if (data->map[(int)(x + margin) / BLOCK_SIZE][(int)(y - margin)
		/ BLOCK_SIZE] == '1')
		return (1);
	if (data->map[(int)(x - margin) / BLOCK_SIZE][(int)(y + margin)
		/ BLOCK_SIZE] == '1')
		return (1);
	if (data->map[(int)(x + margin) / BLOCK_SIZE][(int)(y + margin)
		/ BLOCK_SIZE] == '1')
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

static t_move	get_move(t_data *data, float cos_angle, float sin_angle,
	int speed)
{
	t_move	m;
	int		vert;
	int		horiz;

	vert = sign_axis(data->player.move_up, data->player.move_down);
	horiz = sign_axis(data->player.move_left, data->player.move_right);
	m.dx = (int)(sin_angle * speed * vert - cos_angle * speed * horiz);
	m.dy = (int)(cos_angle * speed * vert + sin_angle * speed * horiz);
	return (m);
}

void	move_player(t_data *data, float cos_angle, float sin_angle,
	int speed)
{
	t_move	m;
	int		nx;
	int		ny;

	m = get_move(data, cos_angle, sin_angle, speed);
	nx = data->player.pos.x;
	ny = data->player.pos.y;
	if (m.dx != 0 && !is_wall(data, nx + m.dx, ny))
		nx += m.dx;
	if (m.dy != 0 && !is_wall(data, nx, ny + m.dy))
		ny += m.dy;
	data->player.pos.x = nx;
	data->player.pos.y = ny;
}
