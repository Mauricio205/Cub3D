/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	load_door_frame(t_data *data, t_image *tex, char *path)
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
	resize_to_tex(data, tex);
}

void	load_door_textures(t_data *data)
{
	char	path[64];
	char	num[3];
	int		i;

	i = 0;
	while (i < DOOR_FRAMES)
	{
		path[0] = '\0';
		ft_strlcat(path, DOOR_PATH, sizeof(path));
		ft_strlcat(path, "door", sizeof(path));
		if (i == DOOR_FRAMES - 1)
			ft_strlcat(path, "100", sizeof(path));
		else
		{
			num[0] = '0' + i;
			num[1] = '0';
			num[2] = '\0';
			ft_strlcat(path, num, sizeof(path));
		}
		ft_strlcat(path, ".xpm", sizeof(path));
		load_door_frame(data, &data->tex_door[i], path);
		i++;
	}
}

t_door	*find_door(t_data *data, int map_x, int map_y)
{
	t_door	*door;

	door = data->doors;
	while (door)
	{
		if (door->map_x == map_x && door->map_y == map_y)
			return (door);
		door = door->next;
	}
	return (NULL);
}

int	is_door_closed(t_data *data, int map_x, int map_y)
{
	if (!data->map[map_x] || map_y < 0
		|| map_y >= (int)ft_strlen(data->map[map_x]))
		return (0);
	return (data->map[map_x][map_y] == 'D');
}
