/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <maumonte@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-07 12:44:27 by maumonte          #+#    #+#             */
/*   Updated: 2026-09-07 12:44:27 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	inside_minimap_circle(int x, int y)
{
	int	cx;
	int	cy;
	int	dx;
	int	dy;
	int	radius;

	cx = MINIMAP_OFFSET_X + MINIMAP_WIDTH / 2;
	cy = MINIMAP_OFFSET_Y + MINIMAP_HEIGHT / 2;
	radius = MINIMAP_WIDTH / 2;
	dx = x - cx;
	dy = y - cy;
	return (dx * dx + dy * dy <= radius * radius);
}

void	draw_square(t_image *image, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = MINIMAP_TILE_SIZE;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (inside_minimap_circle(x + i, y + j))
				my_mlx_pixel_put(image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_data *data, t_image *image, int x, int y)
{
	int	dx;
	int	dy;
	int	radius;

	radius = MINIMAP_TILE_SIZE / 2;
	dy = -radius;
	while (dy <= radius)
	{
		dx = -radius;
		while (dx <= radius)
		{
			if (dx * dx + dy * dy <= radius * radius
				&& inside_minimap_circle(x + dx, y + dy)
				&& !minimap_pixel_is_wall(data, x + dx - MINIMAP_OFFSET_X
					- MINIMAP_WIDTH / 2, y + dy - MINIMAP_OFFSET_Y
					- MINIMAP_HEIGHT / 2))
				my_mlx_pixel_put(image, x + dx, y + dy, MINIMAP_SPRITE_COLOR);
			dx++;
		}
		dy++;
	}
}

int	minimap_cell_color(char cell)
{
	if (cell == '1')
		return (0xa5f970);
	if (cell == 'D')
		return (MINIMAP_DOOR_CLOSED_COLOR);
	if (cell == 'd')
		return (MINIMAP_DOOR_OPEN_COLOR);
	return (0x4b736b);
}

void	draw_rotated_player(t_data *data, t_image *image, t_image *img)
{
	int				dx;
	int				dy;
	unsigned int	color;

	dy = -MINIMAP_PLAYER_SIZE / 2;
	while (dy <= MINIMAP_PLAYER_SIZE / 2)
	{
		dx = -MINIMAP_PLAYER_SIZE / 2;
		while (dx <= MINIMAP_PLAYER_SIZE / 2)
		{
			color = get_player_pixel(data, img, dx, dy);
			if (color != 0)
				my_mlx_pixel_put(image, dx + data->mini.px,
					dy + data->mini.py, color);
			dx++;
		}
		dy++;
	}
}
