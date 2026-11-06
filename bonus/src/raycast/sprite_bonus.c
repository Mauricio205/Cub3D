/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	load_one_sprite_frame(t_data *data, t_image *tex, char *path)
{
	int	w;
	int	h;

	tex->img = mlx_xpm_file_to_image(data->data.mlx, path, &w, &h);
	if (!tex->img)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nfalha ao carregar sprite!", 2);
		(cleanup(data), exit(1));
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->size_line, &tex->endian);
	tex->width = w;
	tex->height = h;
	tex->aspect = (float)w / (float)h;
	resize_to_tex(data, tex);
}

void	load_sprite_frames(t_data *data)
{
	char	path[80];
	char	num[4];
	int		i;

	i = 0;
	while (i < SPRITE_COUNT)
	{
		path[0] = '\0';
		ft_strlcat(path, SPRITE_PATH, sizeof(path));
		ft_strlcat(path, "frame_", sizeof(path));
		num[0] = '0' + (i + 1) / 10;
		num[1] = '0' + (i + 1) % 10;
		num[2] = '\0';
		ft_strlcat(path, num, sizeof(path));
		ft_strlcat(path, ".xpm", sizeof(path));
		load_one_sprite_frame(data, &data->sprite_frames[i], path);
		i++;
	}
}
