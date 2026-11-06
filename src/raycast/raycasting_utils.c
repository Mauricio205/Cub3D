/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:26:06 by saalexan          #+#    #+#             */
/*   Updated: 2026/08/24 13:39:32 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
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

int	rgb_to_int(t_color	color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

static void	load_one_texture(t_data *data, t_image *tex, char *path)
{
	int	w;
	int	h;

	tex->img = mlx_xpm_file_to_image(data->data.mlx, path, &w, &h);
	if (!tex->img)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nfalha ao carregar textura!", 2);
		(cleanup(data), exit(1));
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->size_line, &tex->endian);
	tex->width = w;
	tex->height = h;
}

void	load_textures(t_data *data)
{
	load_one_texture(data, &data->tex_no, data->texture.no);
	load_one_texture(data, &data->tex_so, data->texture.so);
	load_one_texture(data, &data->tex_we, data->texture.we);
	load_one_texture(data, &data->tex_ea, data->texture.ea);
	build_mipmaps(&data->tex_no);
	build_mipmaps(&data->tex_so);
	build_mipmaps(&data->tex_we);
	build_mipmaps(&data->tex_ea);
}
