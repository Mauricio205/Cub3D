/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_anim_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	sprite_cell_blocked(t_data *data, int map_x, int map_y)
{
	char	cell;

	if (map_x < 0 || map_y < 0 || map_x >= data->count_line
		|| map_y >= (int)ft_strlen(data->map[map_x]))
		return (1);
	cell = data->map[map_x][map_y];
	if (cell == '1' || cell == ' ' || cell == '\n')
		return (1);
	if (cell == 'D' && is_door_closed(data, map_x, map_y))
		return (1);
	return (0);
}

static int	sprite_is_wall(t_data *data, float x, float y)
{
	int	m;
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	m = BLOCK_SIZE / 2 - 2;
	if (x - m < 0 || y - m < 0)
		return (1);
	x0 = (int)((x - m) / BLOCK_SIZE);
	x1 = (int)((x + m) / BLOCK_SIZE);
	y0 = (int)((y - m) / BLOCK_SIZE);
	y1 = (int)((y + m) / BLOCK_SIZE);
	if (sprite_cell_blocked(data, x0, y0) || sprite_cell_blocked(data, x1, y0))
		return (1);
	if (sprite_cell_blocked(data, x0, y1) || sprite_cell_blocked(data, x1, y1))
		return (1);
	return (0);
}

static int	sprite_step(t_data *data, t_sprite *sp, float vx, float vy)
{
	int	moved;

	moved = 0;
	if (!sprite_is_wall(data, sp->x + vx, sp->y))
	{
		sp->x += vx;
		moved = 1;
	}
	if (!sprite_is_wall(data, sp->x, sp->y + vy))
	{
		sp->y += vy;
		moved = 1;
	}
	return (moved);
}

static int	sprite_chase(t_data *data, t_sprite *sp)
{
	float	dx;
	float	dy;
	float	norm;
	float	vx;
	float	vy;

	dx = data->player.pos.x - sp->x;
	dy = data->player.pos.y - sp->y;
	norm = sqrtf(dx * dx + dy * dy);
	if (norm < SPRITE_COLLISION)
	{
		data->game_over = 1;
		return (2);
	}
	if (norm < 0.001f)
		norm = 0.001f;
	vx = dx / norm * SPRITE_SPEED;
	vy = dy / norm * SPRITE_SPEED;
	return (sprite_step(data, sp, vx, vy));
}

int	move_sprites(t_data *data)
{
	int	i;
	int	changed;
	int	upd;

	if (!data->sprites || data->sprite_count == 0)
		return (0);
	changed = 0;
	i = 0;
	while (i < data->sprite_count)
	{
		upd = sprite_chase(data, &data->sprites[i]);
		if (upd == 2)
			return (1);
		if (upd == 1)
			changed = 1;
		i++;
	}
	return (changed);
}
