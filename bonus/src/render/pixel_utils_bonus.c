/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (!data->addr)
		return ;
	if (x >= data->width || y >= data->height || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	update_camera_vectors(t_player *player)
{
	float	half_fov_tan;

	half_fov_tan = tanf(FOV / 2.0f);
	player->dir_x = cosf(player->angle);
	player->dir_y = sinf(player->angle);
	player->plane_x = -sinf(player->angle) * half_fov_tan;
	player->plane_y = cosf(player->angle) * half_fov_tan;
}

int	rgb_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

void	overlay_pixel(t_image *img, int x, int y, unsigned int color)
{
	unsigned int	*bg;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	bg = (unsigned int *)(img->addr + (y * img->size_line
				+ x * (img->bits_per_pixel / 8)));
	*bg = color;
}
