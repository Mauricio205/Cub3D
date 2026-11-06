/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:25:02 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	calc_delta_dist(t_data *data, t_raycast *ray, int x)
{
	ray->camera_x = 2 * x / (float)WIDTH - 1;
	ray->ray_dir_x = data->player.dir_x + data->player.plane_x
		* ray->camera_x;
	ray->ray_dir_y = data->player.dir_y + data->player.plane_y
		* ray->camera_x;
	ray->pos_x = data->player.pos.y / (float)BLOCK_SIZE;
	ray->pos_y = data->player.pos.x / (float)BLOCK_SIZE;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabsf(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabsf(1 / ray->ray_dir_y);
}

static void	calc_side_dist(t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0f - ray->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0f - ray->pos_y)
			* ray->delta_dist_y;
	}
}

static t_image	*select_texture(t_data *data, t_raycast *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&data->tex_ea);
		return (&data->tex_we);
	}
	if (ray->ray_dir_y > 0)
		return (&data->tex_so);
	return (&data->tex_no);
}

static void	draw_column(t_data *data, t_image *img, t_raycast *ray, int x)
{
	float	wall_x;

	ray->tex = select_texture(data, ray);
	if (ray->side == 0)
		wall_x = ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floorf(wall_x);
	insert_texture(img, *ray, x, wall_x);
	if (ray->hit_door && ray->door_perp_dist < ray->perp_wall_dist)
		data->z_buffer[x] = ray->door_perp_dist;
	else
		data->z_buffer[x] = ray->perp_wall_dist;
	if (ray->hit_door)
		insert_door(data, img, ray, x);
}

void	raycast(t_data *data, t_image *img)
{
	int			x;
	t_raycast	ray;

	x = 0;
	while (x < WIDTH)
	{
		calc_delta_dist(data, &ray, x);
		calc_side_dist(&ray);
		calc_perp_wall_dist(data, &ray);
		ray.line_height = (int)(HEIGHT / ray.perp_wall_dist);
		ray.draw_start = -ray.line_height / 2 + HEIGHT / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.line_height / 2 + HEIGHT / 2;
		if (ray.draw_end >= HEIGHT)
			ray.draw_end = HEIGHT - 1;
		draw_column(data, img, &ray, x);
		x++;
	}
}
