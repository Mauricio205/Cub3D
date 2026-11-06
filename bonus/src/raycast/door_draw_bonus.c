/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_draw_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	clamp_tex_coord(int value, int max)
{
	if (value < 0)
		return (0);
	if (value >= max)
		return (max - 1);
	return (value);
}

static void	door_bounds(float line_height, t_sampler *s)
{
	s->draw_start = (int)(-line_height / 2 + HEIGHT / 2);
	if (s->draw_start < 0)
		s->draw_start = 0;
	s->draw_end = (int)(line_height / 2 + HEIGHT / 2);
	if (s->draw_end >= HEIGHT)
		s->draw_end = HEIGHT - 1;
}

static t_sampler	door_sampler(t_data *data, t_raycast *ray, int x)
{
	t_sampler	s;
	t_image		*t;
	float		line_height;
	int			offset;

	t = &data->tex_door[door_frame_index(data, ray)];
	line_height = HEIGHT / ray->door_perp_dist;
	door_bounds(line_height, &s);
	s.tex = t;
	s.x = x;
	s.bpp = t->bits_per_pixel / 8;
	s.ifu = clamp_tex_coord((int)(door_wall_x(ray) * t->width), t->width);
	s.step = (float)t->height / line_height;
	offset = (int)(-line_height / 2 + HEIGHT / 2);
	s.tex_pos = (s.draw_start - offset) * (float)s.step;
	return (s);
}

static void	draw_door_pixels(t_image *img, t_sampler s)
{
	int				y;
	int				tex_y;
	unsigned int	c;

	y = s.draw_start;
	while (y < s.draw_end)
	{
		tex_y = (int)s.tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= s.tex->height)
			tex_y = s.tex->height - 1;
		c = *(unsigned int *)(s.tex->addr + (tex_y * s.tex->size_line
					+ s.ifu * s.bpp));
		if (c != TX_TRANSPARENT)
			overlay_pixel(img, s.x, y, c);
		s.tex_pos += s.step;
		y++;
	}
}

void	insert_door(t_data *data, t_image *img, t_raycast *ray, int x)
{
	t_sampler	s;

	s = door_sampler(data, ray, x);
	draw_door_pixels(img, s);
}
