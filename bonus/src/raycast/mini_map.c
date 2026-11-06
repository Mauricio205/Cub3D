/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_mapa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <maumonte@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-27 11:48:58 by maumonte          #+#    #+#             */
/*   Updated: 2026-08-27 11:48:58 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_player_minimap(t_data *data, t_image *image)
{
	t_image			img;

	data->mini.cos_a = cos(data->player.angle);
	data->mini.sin_a = sin(data->player.angle);
	data->mini.size = data->mini.player_img_width;
	data->mini.px = MINIMAP_OFFSET_X + MINIMAP_WIDTH / 2;
	data->mini.py = MINIMAP_OFFSET_Y + MINIMAP_HEIGHT / 2;
	img.img = data->mini.player_img;
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel,
			&img.size_line,
			&img.endian);
	draw_rotated_player(data, image, &img);
}

static void	draw_minimap_map(t_data *data, t_image *image)
{
	float	player_x;
	float	player_y;

	player_x = data->player.pos.y / (float)BLOCK_SIZE;
	player_y = data->player.pos.x / (float)BLOCK_SIZE;
	draw_minimap_map_aux(data, image, player_x, player_y);
}

static void	draw_minimap_background(t_image *image)
{
	int	x;
	int	y;

	y = MINIMAP_OFFSET_Y;
	while (y < MINIMAP_OFFSET_Y + MINIMAP_HEIGHT)
	{
		x = MINIMAP_OFFSET_X;
		while (x < MINIMAP_OFFSET_X + MINIMAP_WIDTH)
		{
			if (inside_minimap_circle(x, y))
				my_mlx_pixel_put(image, x, y, 0x4b736b);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data, t_image *image)
{
	draw_minimap_background(image);
	draw_minimap_map(data, image);
	draw_player_minimap(data, image);
}
