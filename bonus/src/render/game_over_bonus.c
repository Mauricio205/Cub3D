/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_game_over_image(t_data *data)
{
	int	w;
	int	h;

	if (data->game_over_loaded)
		return ;
	data->game_over_tex.img = mlx_xpm_file_to_image(data->data.mlx,
			GAME_OVER_PATH, &w, &h);
	if (!data->game_over_tex.img)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nfalha ao carregar game over!",
			2);
		(cleanup(data), exit(1));
	}
	data->game_over_tex.addr = mlx_get_data_addr(data->game_over_tex.img,
			&data->game_over_tex.bits_per_pixel, &data->game_over_tex.size_line,
			&data->game_over_tex.endian);
	data->game_over_tex.width = w;
	data->game_over_tex.height = h;
	data->game_over_loaded = 1;
}

static void	draw_game_over_scaled(t_data *data, t_image *img)
{
	int				x;
	int				y;
	int				tex_x;
	int				tex_y;
	unsigned int	c;

	y = 0;
	while (y < HEIGHT)
	{
		tex_y = y * data->game_over_tex.height / HEIGHT;
		x = 0;
		while (x < WIDTH)
		{
			tex_x = x * data->game_over_tex.width / WIDTH;
			c = *(unsigned int *)(data->game_over_tex.addr + tex_y
					* data->game_over_tex.size_line + tex_x
					* (data->game_over_tex.bits_per_pixel / 8));
			my_mlx_pixel_put(img, x, y, c);
			x++;
		}
		y++;
	}
}

void	show_game_over(t_data *data)
{
	t_image	img;

	if (!data->game_over_loaded)
		load_game_over_image(data);
	if (data->game_over_drawn)
		return ;
	data->game_over_drawn = 1;
	img.img = mlx_new_image(data->data.mlx, WIDTH, HEIGHT);
	if (!img.img)
	{
		printf("Erro ao criar a imagem.\n");
		exit(1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	img.width = WIDTH;
	img.height = HEIGHT;
	draw_game_over_scaled(data, &img);
	mlx_put_image_to_window(data->data.mlx, data->data.win, img.img, 0, 0);
	mlx_destroy_image(data->data.mlx, img.img);
}
