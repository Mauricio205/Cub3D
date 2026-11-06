/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_toggle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	row_width(char *row)
{
	int	len;

	len = ft_strlen(row);
	if (len > 0 && row[len - 1] == '\n')
		return (len - 1);
	return (len);
}

static t_door	*door_in_front(t_data *data)
{
	float	dist;
	int		map_x;
	int		map_y;

	dist = 0;
	while (dist <= DOOR_REACH)
	{
		map_x = (int)((data->player.pos.x + sinf(data->player.angle) * dist)
				/ BLOCK_SIZE);
		map_y = (int)((data->player.pos.y + cosf(data->player.angle) * dist)
				/ BLOCK_SIZE);
		if (map_x < 0 || map_y < 0 || map_x >= data->count_line
			|| !data->map[map_x]
			|| map_y >= row_width(data->map[map_x]))
			return (NULL);
		if (data->map[map_x][map_y] == '1')
			return (NULL);
		if (data->map[map_x][map_y] == 'D' || data->map[map_x][map_y] == 'd')
			return (find_door(data, map_x, map_y));
		dist += 2;
	}
	return (NULL);
}

void	toggle_door(t_data *data)
{
	t_door	*door;

	door = door_in_front(data);
	if (!door || door->moving)
		return ;
	if (door->progress == 0)
		door->moving = 1;
	else
	{
		if ((int)(data->player.pos.x / BLOCK_SIZE) == door->map_x
			&& (int)(data->player.pos.y / BLOCK_SIZE) == door->map_y)
			return ;
		door->moving = -1;
	}
}
