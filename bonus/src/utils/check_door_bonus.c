/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/22 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	is_wall(t_data *map, int x, int y)
{
	return (get_cell(map, x, y) == '1');
}

static int	between_walls(t_data *map, int x, int y)
{
	int	walls;
	int	horizontal;
	int	vertical;

	walls = is_wall(map, x - 1, y) + is_wall(map, x + 1, y);
	walls += is_wall(map, x, y - 1) + is_wall(map, x, y + 1);
	horizontal = is_wall(map, x, y - 1) && is_wall(map, x, y + 1);
	vertical = is_wall(map, x - 1, y) && is_wall(map, x + 1, y);
	if (walls != 2)
		return (0);
	return (horizontal || vertical);
}

static void	door_error(t_data *map)
{
	ft_putendl_fd("\e[1;31mError\e[0m\nporta inválida, a porta "
		"precisa de duas paredes em lados opostos!", 2);
	(cleanup(map), exit(1));
}

void	check_door(t_data *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->index_map)
	{
		y = 0;
		while (map->map[x][y])
		{
			if ((map->map[x][y] == 'D' || map->map[x][y] == 'd')
				&& !between_walls(map, x, y))
				door_error(map);
			y++;
		}
		x++;
	}
}
