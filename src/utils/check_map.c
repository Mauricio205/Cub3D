/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:54:51 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/22 10:59:46 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	message_error_wall(t_data *map)
{
	ft_putendl_fd("\e[1;31mError\e[0m\nmapa não delimitado com paredes!", 2);
	cleanup(map);
	exit(1);
}

char	get_cell(t_data *map, int x, int y)
{
	if (x < 0 || x >= map->index_map)
		return (' ');
	if (y < 0 || y >= (int)ft_strlen(map->map[x]) - 1)
		return (' ');
	return (map->map[x][y]);
}

int	check_cell(t_data *map, int x, int y)
{
	if (get_cell(map, x - 1, y) == ' ')
		return (0);
	if (get_cell(map, x + 1, y) == ' ')
		return (0);
	if (get_cell(map, x, y - 1) == ' ')
		return (0);
	if (get_cell(map, x, y + 1) == ' ')
		return (0);
	return (1);
}

void	check_is_around_wall(t_data *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->index_map)
	{
		y = 0;
		while (map->map[x][y])
		{
			if (map->map[x][y] == '0'
			|| map->map[x][y] == 'N'
			|| map->map[x][y] == 'S'
			|| map->map[x][y] == 'W'
			|| map->map[x][y] == 'E')
			{
				if (!check_cell(map, x, y))
					message_error_wall(map);
			}
			y++;
		}
		x++;
	}
}

void	check_extension_map(t_data *map, char *av)
{
	char	*p;
	char	*ptr;

	p = ft_strrchr(av, '.');
	ptr = ft_strdup(p);
	if (ft_strncmp(ptr, ".cub", ft_strlen(ptr))
		|| !ft_strncmp(av, ".cub", ft_strlen(av)))
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nnmapa inválido(extensão)!", 2);
		cleanup(map);
		free(ptr);
		exit (1);
	}
	free(ptr);
}
