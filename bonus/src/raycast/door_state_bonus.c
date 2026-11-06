/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_state_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	push_door(t_data *data, int x, int y)
{
	t_door	*door;
	t_door	*last;

	door = malloc(sizeof(t_door));
	if (!door)
		(cleanup(data), exit(1));
	door->map_x = x;
	door->map_y = y;
	door->progress = 0;
	door->moving = 0;
	door->next = NULL;
	last = data->doors;
	if (!last)
	{
		data->doors = door;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = door;
}

void	init_doors(t_data *data)
{
	int	x;
	int	y;

	data->doors = NULL;
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'D' || data->map[x][y] == 'd')
				push_door(data, x, y);
			y++;
		}
		x++;
	}
}

static void	move_door(t_data *data, t_door *door)
{
	door->progress += DOOR_SPEED * door->moving;
	if (door->progress <= 0 || door->progress >= 100)
	{
		door->progress = 100 * (door->moving > 0);
		door->moving = 0;
	}
	if (door->progress >= 50 && data->map[door->map_x][door->map_y] == 'D')
		data->map[door->map_x][door->map_y] = 'd';
	else if (door->progress < 50
		&& data->map[door->map_x][door->map_y] == 'd')
		data->map[door->map_x][door->map_y] = 'D';
}

int	update_doors(t_data *data)
{
	t_door	*door;
	int		animating;

	animating = 0;
	door = data->doors;
	while (door)
	{
		if (door->moving)
		{
			move_door(data, door);
			animating = 1;
		}
		door = door->next;
	}
	return (animating);
}

int	cell_blocked(t_data *data, int map_x, int map_y)
{
	char	cell;

	if (map_x < 0 || map_y < 0 || !data->map[map_x]
		|| map_y >= (int)ft_strlen(data->map[map_x]))
		return (1);
	cell = data->map[map_x][map_y];
	if (cell == '1')
		return (1);
	if (cell == 'D')
		return (1);
	return (0);
}
