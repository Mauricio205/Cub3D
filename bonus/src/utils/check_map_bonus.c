/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:54:51 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:18:54 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	message_error_wall(t_data *map)
{
	ft_putendl_fd("\e[1;31mError\e[0m\nmapa não delimitado com paredes!", 2);
	cleanup(map);
	exit(1);
}

static int	map_row_width(char *row)
{
	int	len;

	len = ft_strlen(row);
	if (len > 0 && row[len - 1] == '\n')
		return (len - 1);
	return (len);
}

char	get_cell(t_data *map, int x, int y)
{
	if (x < 0 || x >= map->index_map)
		return (' ');
	if (y < 0 || y >= map_row_width(map->map[x]))
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
			if (map->map[x][y] == '0' || map->map[x][y] == 'D'
			|| map->map[x][y] == 'd' || map->map[x][y] == 'M'
			|| map->map[x][y] == 'N' || map->map[x][y] == 'S'
			|| map->map[x][y] == 'W' || map->map[x][y] == 'E')
			{
				if (!check_cell(map, x, y))
					message_error_wall(map);
			}
			y++;
		}
		x++;
	}
	check_door(map);
}
