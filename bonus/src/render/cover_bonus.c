/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/22 09:20:38 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_cover_scaled(t_image *tex, t_image *img)
{
	int				x;
	int				y;
	int				tex_x;
	int				tex_y;
	unsigned int	c;

	y = 0;
	while (y < HEIGHT)
	{
		tex_y = y * tex->height / HEIGHT;
		x = 0;
		while (x < WIDTH)
		{
			tex_x = x * tex->width / WIDTH;
			c = *(unsigned int *)(tex->addr + tex_y * tex->size_line + tex_x
					* (tex->bits_per_pixel / 8));
			my_mlx_pixel_put(img, x, y, c);
			x++;
		}
		y++;
	}
}

static void	paint_cover(t_data *data, int index)
{
	t_image	img;

	img.img = mlx_new_image(data->data.mlx, WIDTH, HEIGHT);
	if (!img.img)
		exit(1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	img.width = WIDTH;
	img.height = HEIGHT;
	draw_cover_scaled(&data->cover_tex[index], &img);
	mlx_put_image_to_window(data->data.mlx, data->data.win, img.img, 0, 0);
	mlx_destroy_image(data->data.mlx, img.img);
}

void	show_cover(t_data *data)
{
	load_cover_images(data);
	if (!data->cover_start)
		data->cover_start = time(NULL);
	if (time(NULL) - data->cover_start >= COVER_DELAY_SEC)
	{
		data->cover_timer++;
		if (data->cover_timer >= COVER_ANIM_SPEED)
		{
			data->cover_timer = 0;
			data->cover_index = 1 + (data->cover_index % 3);
		}
	}
	else
		data->cover_index = 0;
	paint_cover(data, data->cover_index);
}

void	cover_image_delete(t_data *data)
{
	int	i;

	if (!data->cover_loaded)
		return ;
	i = 0;
	while (i < COVER_NB)
	{
		if (data->cover_tex[i].img)
			mlx_destroy_image(data->data.mlx, data->cover_tex[i].img);
		i++;
	}
	data->cover_loaded = 0;
}
