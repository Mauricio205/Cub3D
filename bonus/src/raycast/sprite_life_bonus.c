/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_life_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	animate_sprites(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sprite_count)
	{
		data->sprites[i].anim_timer++;
		if (data->sprites[i].anim_timer >= SPRITE_ANIM_SPEED)
		{
			data->sprites[i].anim_timer = 0;
			data->sprites[i].current_frame++;
			if (data->sprites[i].current_frame >= SPRITE_COUNT)
				data->sprites[i].current_frame = 0;
		}
		i++;
	}
}

void	free_sprites(t_data *data)
{
	int	i;

	i = 0;
	while (i < SPRITE_COUNT)
	{
		if (data->sprite_frames[i].img)
			mlx_destroy_image(data->data.mlx, data->sprite_frames[i].img);
		i++;
	}
	if (data->sprites)
		free(data->sprites);
	data->sprites = NULL;
}
