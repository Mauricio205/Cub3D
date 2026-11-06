/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	sprite_distances(t_data *data)
{
	int		i;
	float	dx;
	float	dy;

	i = 0;
	while (i < data->sprite_count)
	{
		dx = data->sprites[i].x - data->player.pos.x;
		dy = data->sprites[i].y - data->player.pos.y;
		data->sprites[i].dist = dx * dx + dy * dy;
		i++;
	}
}

static void	swap_sprites(t_sprite *a, t_sprite *b)
{
	t_sprite	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	order_sprites(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->sprite_count - 1)
	{
		j = 0;
		while (j < data->sprite_count - 1 - i)
		{
			if (data->sprites[j].dist < data->sprites[j + 1].dist)
				swap_sprites(&data->sprites[j], &data->sprites[j + 1]);
			j++;
		}
		i++;
	}
}

void	sort_sprites(t_data *data)
{
	sprite_distances(data);
	order_sprites(data);
}
