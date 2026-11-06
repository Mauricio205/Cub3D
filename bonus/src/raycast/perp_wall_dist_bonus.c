/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perp_wall_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:57:07 by saalexan          #+#    #+#             */
/*   Updated: 2026/08/21 12:51:30 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	out_of_bounds(t_data *data, int row, int col)
{
	int	h;
	int	w;

	h = 0;
	while (data->map[h])
		h++;
	if (row < 0 || row >= h)
		return (1);
	w = ft_strlen(data->map[row]);
	if (w > 0 && data->map[row][w - 1] == '\n')
		w--;
	return (col < 0 || col >= w);
}

static void	get_perp_wall_dist(t_raycast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - ray->pos_x
				+ (1 - ray->step_x) / 2.0f) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - ray->pos_y
				+ (1 - ray->step_y) / 2.0f) / ray->ray_dir_y;
}

static void	dda_step(t_raycast *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

static void	detect_door(t_data *data, t_raycast *ray)
{
	if (ray->hit_door)
		return ;
	ray->hit_door = 1;
	ray->door_open = (data->map[ray->map_y][ray->map_x] == 'd');
	ray->door_side = ray->side;
	ray->door_map_x = ray->map_x;
	ray->door_map_y = ray->map_y;
	get_perp_wall_dist(ray);
	ray->door_perp_dist = ray->perp_wall_dist;
}

void	calc_perp_wall_dist(t_data *data, t_raycast *ray)
{
	int	max_iter;

	ray->side = 0;
	ray->hit_door = 0;
	ray->door_open = 0;
	ray->door_perp_dist = 0;
	ray->door_side = 0;
	max_iter = 1000;
	while (max_iter-- > 0 && !out_of_bounds(data, ray->map_y, ray->map_x))
	{
		if (data->map[ray->map_y][ray->map_x] == '1')
			break ;
		if (data->map[ray->map_y][ray->map_x] == 'D'
			|| data->map[ray->map_y][ray->map_x] == 'd')
			detect_door(data, ray);
		dda_step(ray);
	}
	get_perp_wall_dist(ray);
}
