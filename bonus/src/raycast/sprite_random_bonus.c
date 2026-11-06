/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_random_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <time.h>

static int	fallback_spawn(t_data *data, int *cx, int *cy)
{
	*cx = 0;
	while (*cx < data->count_line)
	{
		*cy = 0;
		while (*cy < (int)ft_strlen(data->map[*cx]))
		{
			if (is_valid_spawn(data, *cx, *cy))
				return (1);
			(*cy)++;
		}
		(*cx)++;
	}
	return (0);
}

static void	store_sprite(t_data *data, int idx, int cx, int cy)
{
	data->sprites[idx].x = cx * BLOCK_SIZE + BLOCK_SIZE / 2;
	data->sprites[idx].y = cy * BLOCK_SIZE + BLOCK_SIZE / 2;
	data->sprites[idx].dist = 0;
	data->sprites[idx].current_frame = idx * 2;
	data->sprites[idx].anim_timer = idx * 3;
}

static void	spawn_random_sprites(t_data *data)
{
	int	idx;
	int	tries;
	int	cx;
	int	cy;

	srand(time(NULL));
	idx = 0;
	while (idx < SPRITE_NB && data->count_line > 0)
	{
		tries = 0;
		while (tries < 1000)
		{
			cx = rand() % data->count_line;
			cy = random_cell_y(data, cx);
			if (is_valid_spawn(data, cx, cy))
				break ;
			tries++;
		}
		if (tries >= 1000 && !fallback_spawn(data, &cx, &cy))
			break ;
		store_sprite(data, idx, cx, cy);
		data->sprite_count++;
		idx++;
	}
}

void	init_sprites(t_data *data)
{
	data->sprites = NULL;
	data->sprite_count = 0;
	data->sprites = malloc(sizeof(t_sprite) * SPRITE_NB);
	if (!data->sprites)
		(cleanup(data), exit(1));
	spawn_random_sprites(data);
}
