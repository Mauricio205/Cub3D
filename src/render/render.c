/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:51:56 by saalexan          #+#    #+#             */
/*   Updated: 2026/08/24 13:33:27 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ceiling_and_floor(t_data *data, t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
			my_mlx_pixel_put(img, j++, i, rgb_to_int(data->ceiling));
		i++;
	}
	while (i < HEIGHT - 1)
	{
		j = 0;
		while (j < WIDTH)
			my_mlx_pixel_put(img, j++, i, rgb_to_int(data->floor));
		i++;
	}
}

void	render(t_data *data)
{
	t_image	img;

	img.img = mlx_new_image(data->data.mlx, WIDTH, HEIGHT);
	if (!img.img)
	{
		printf("Erro ao criar a imagem.\n");
		exit(1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.size_line, &img.endian);
	ceiling_and_floor(data, &img);
	raycast(data, &img);
	mlx_put_image_to_window(data->data.mlx, data->data.win, img.img, 0, 0);
	mlx_destroy_image(data->data.mlx, img.img);
}

static char	get_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->player.pos = (t_position){i * BLOCK_SIZE + BLOCK_SIZE
					/ (2 * SIZE_PLAYER), j * BLOCK_SIZE + BLOCK_SIZE
					/ (2 * SIZE_PLAYER)};
				return (data->map[i][j]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_player(t_data *data)
{
	char	look_to;

	look_to = get_pos(data);
	if (look_to == 'E')
		data->player.angle = 0;
	else if (look_to == 'N')
		data->player.angle = (3 * PI) / 2;
	else if (look_to == 'W')
		data->player.angle = PI;
	else
		data->player.angle = PI / 2;
	data->player.old_pos = (t_position){-1, -1};
	data->player.look_left = 0;
	data->player.look_right = 0;
	data->player.move_left = 0;
	data->player.move_right = 0;
	data->player.move_up = 0;
	data->player.move_down = 0;
	update_camera_vectors(&data->player);
}
