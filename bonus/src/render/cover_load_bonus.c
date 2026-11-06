/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover_load_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	build_cover_path(char *path, char *num, int i, int size)
{
	path[0] = '\0';
	if (i == 0)
		ft_strlcat(path, COVER_PATH, size);
	else
	{
		ft_strlcat(path, "./textures/cover/cover_", size);
		num[0] = '0' + i;
		num[1] = '\0';
		ft_strlcat(path, num, size);
		ft_strlcat(path, ".xpm", size);
	}
}

static void	load_one_cover(t_data *data, char *path, int i)
{
	data->cover_tex[i].img = mlx_xpm_file_to_image(data->data.mlx, path,
			&data->cover_tex[i].width, &data->cover_tex[i].height);
	if (!data->cover_tex[i].img)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nfalha ao carregar cover!",
			2);
		(cleanup(data), exit(1));
	}
	data->cover_tex[i].addr = mlx_get_data_addr(data->cover_tex[i].img,
			&data->cover_tex[i].bits_per_pixel,
			&data->cover_tex[i].size_line, &data->cover_tex[i].endian);
}

void	load_cover_images(t_data *data)
{
	char	path[80];
	char	num[2];
	int		i;

	if (data->cover_loaded)
		return ;
	i = 0;
	while (i < COVER_NB)
	{
		build_cover_path(path, num, i, sizeof(path));
		load_one_cover(data, path, i);
		i++;
	}
	data->cover_loaded = 1;
}
