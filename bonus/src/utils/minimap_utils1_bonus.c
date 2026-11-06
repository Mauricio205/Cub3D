/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <maumonte@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-21 12:42:01 by maumonte          #+#    #+#             */
/*   Updated: 2026-09-21 12:42:01 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_player_minimap(t_data *data)
{
	data->mini.player_img = mlx_xpm_file_to_image(data->data.mlx,
			"./textures/player2.xpm",
			&data->mini.player_img_width,
			&data->mini.player_img_height);
	if (!data->mini.player_img)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nfalha ao carregar textura!", 2);
		(cleanup(data), exit(1));
	}
}

void	draw_minimap_map_aux(t_data *data, t_image *image,
		float player_x, float player_y)
{
	int		y;
	int		x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			data->mini.px = MINIMAP_OFFSET_X + MINIMAP_WIDTH / 2
				+ (int)((x - player_x) * MINIMAP_TILE_SIZE);
			data->mini.py = MINIMAP_OFFSET_Y + MINIMAP_HEIGHT / 2
				+ (int)((y - player_y) * MINIMAP_TILE_SIZE);
			draw_square(image, data->mini.px, data->mini.py,
				minimap_cell_color(data->map[y][x]));
			x++;
		}
		y++;
	}
}

static unsigned	int	get_pixel(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->size_line
			+ x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	minimap_pixel_is_wall(t_data *data, int ox, int oy)
{
	int	world_x;
	int	world_y;
	int	cell_x;
	int	cell_y;

	world_x = data->player.pos.x + oy * BLOCK_SIZE / MINIMAP_TILE_SIZE;
	world_y = data->player.pos.y + ox * BLOCK_SIZE / MINIMAP_TILE_SIZE;
	if (world_x < 0 || world_y < 0)
		return (1);
	cell_x = world_x / BLOCK_SIZE;
	cell_y = world_y / BLOCK_SIZE;
	if (!data->map[cell_x] || cell_y >= (int)ft_strlen(data->map[cell_x]))
		return (1);
	return (data->map[cell_x][cell_y] == '1');
}

int	get_player_pixel(t_data *data, t_image *img,
		int dx, int dy)
{
	unsigned int	color;
	int				sx;
	int				sy;

	sx = (int)((dx * data->mini.cos_a + dy * data->mini.sin_a)
			* data->mini.size / MINIMAP_PLAYER_SIZE) + data->mini.size / 2;
	sy = (int)((-dx * data->mini.sin_a + dy * data->mini.cos_a)
			* data->mini.size / MINIMAP_PLAYER_SIZE) + data->mini.size / 2;
	if (sx < 0 || sy < 0 || sx >= data->mini.size || sy >= data->mini.size)
		return (0);
	color = get_pixel(img, sx, sy);
	if ((color & 0x00FFFFFF) == 0 || (color & 0x00FFFFFF) == CELLINGCOLOR
		|| minimap_pixel_is_wall(data, dx, dy))
		return (0);
	return (color);
}
