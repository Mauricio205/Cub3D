/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	project_sprite(t_data *data, t_image *img, int i)
{
	t_proj	p;
	float	sx;
	float	sy;
	float	inv;
	t_image	*tex;

	sx = (data->sprites[i].y - data->player.pos.y) / (float)BLOCK_SIZE;
	sy = (data->sprites[i].x - data->player.pos.x) / (float)BLOCK_SIZE;
	inv = 1.0f / (data->player.plane_x * data->player.dir_y
			- data->player.dir_x * data->player.plane_y);
	p.t0 = inv * (data->player.dir_y * sx - data->player.dir_x * sy);
	p.t1 = inv * (-data->player.plane_y * sx + data->player.plane_x * sy);
	p.screen = (int)((WIDTH / 2) * (1 + p.t0 / p.t1));
	p.size_h = (int)(HEIGHT / p.t1);
	tex = &data->sprite_frames[data->sprites[i].current_frame];
	p.size_w = (int)(p.size_h * tex->aspect);
	p.raw = -p.size_w / 2 + p.screen;
	if (p.t1 > 0.1f)
		draw_sprite(data, img, &data->sprites[i], &p);
}

void	render_sprites(t_data *data, t_image *img)
{
	int	i;

	if (data->sprite_count == 0 || !data->sprites)
		return ;
	sort_sprites(data);
	i = 0;
	while (i < data->sprite_count)
	{
		project_sprite(data, img, i);
		i++;
	}
}
