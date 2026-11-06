/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_geom_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

float	door_wall_x(t_raycast *ray)
{
	float	wx;

	if (ray->door_side == 0)
		wx = ray->pos_y + ray->door_perp_dist * ray->ray_dir_y;
	else
		wx = ray->pos_x + ray->door_perp_dist * ray->ray_dir_x;
	wx -= floorf(wx);
	if (wx < 0)
		wx = 0;
	if (wx >= 1)
		wx = 1 - 1e-6f;
	return (wx);
}

static float	ease_curve(float t)
{
	if (t < 0)
		t = 0;
	if (t > 1)
		t = 1;
	return (0.5f - 0.5f * cosf(t * PI));
}

int	door_frame_index(t_data *data, t_raycast *ray)
{
	t_door	*door;
	int		idx;
	float	progress;
	float	permil;

	door = find_door(data, ray->door_map_y, ray->door_map_x);
	if (door)
		progress = door->progress;
	else
		progress = 100.0f;
	permil = ease_curve(progress / 100.0f);
	idx = (int)roundf(permil * (DOOR_FRAMES - 1));
	if (idx < 0)
		idx = 0;
	if (idx >= DOOR_FRAMES)
		idx = DOOR_FRAMES - 1;
	return (idx);
}
