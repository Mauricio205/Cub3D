/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perp_wall_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:57:07 by saalexan          #+#    #+#             */
/*   Updated: 2026/08/24 13:39:48 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_height(t_data *data)
{
	int	h;

	h = 0;
	while (data->map[h])
		h++;
	return (h);
}

static int	map_width(t_data *data, int row)
{
	int	w;

	w = ft_strlen(data->map[row]);
	if (w > 0 && data->map[row][w - 1] == '\n')
		w--;
	return (w);
}

static int	out_of_bounds(t_data *data, int row, int col)
{
	if (row < 0 || row >= map_height(data))
		return (1);
	if (col < 0 || col >= map_width(data, row))
		return (1);
	return (0);
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

void	calc_perp_wall_dist(t_data *data, t_raycast *ray)
{
	int		max_iter;

	ray->side = 0;
	max_iter = 1000;
	while (max_iter-- > 0)
	{
		if (out_of_bounds(data, ray->map_y, ray->map_x))
			break ;
		if (data->map[ray->map_y][ray->map_x] == '1')
			break ;
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
	get_perp_wall_dist(ray);
}
