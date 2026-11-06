/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	sprite_bounds(int size_h, t_sampler *s)
{
	s->draw_start = -size_h / 2 + HEIGHT / 2;
	if (s->draw_start < 0)
		s->draw_start = 0;
	s->draw_end = size_h / 2 + HEIGHT / 2;
	if (s->draw_end >= HEIGHT)
		s->draw_end = HEIGHT - 1;
}

static t_sampler	sprite_column(t_data *data, t_sprite *sprite, int x,
	int *geo)
{
	t_sampler	s;
	t_image		*tex;
	int			raw;
	int			size_w;
	int			size_h;

	tex = &data->sprite_frames[sprite->current_frame];
	raw = geo[0];
	size_w = geo[2];
	size_h = geo[1];
	s.tex = tex;
	s.x = x;
	s.bpp = tex->bits_per_pixel / 8;
	s.ifu = (int)((x - raw) * (float)tex->width / size_w);
	if (s.ifu < 0)
		s.ifu = 0;
	if (s.ifu >= tex->width)
		s.ifu = tex->width - 1;
	sprite_bounds(size_h, &s);
	s.step = (float)tex->height / size_h;
	s.tex_pos = (s.draw_start - (-size_h / 2 + HEIGHT / 2)) * (float)s.step;
	return (s);
}

static void	draw_sprite_column(t_image *img, t_sampler s)
{
	int				y;
	int				tex_y;
	unsigned int	c;

	y = s.draw_start;
	while (y <= s.draw_end)
	{
		tex_y = (int)s.tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= s.tex->height)
			tex_y = s.tex->height - 1;
		c = *(unsigned int *)(s.tex->addr + (tex_y * s.tex->size_line
					+ s.ifu * s.bpp));
		if (c != TX_TRANSPARENT)
			my_mlx_pixel_put(img, s.x, y, c);
		s.tex_pos += s.step;
		y++;
	}
}

void	draw_sprite(t_data *data, t_image *img, t_sprite *sprite,
	t_proj *p)
{
	int	x0;
	int	x1;
	int	geo[3];

	geo[0] = p->raw;
	geo[1] = p->size_h;
	geo[2] = p->size_w;
	x0 = p->raw;
	x1 = p->size_w / 2 + p->screen;
	if (x0 < 0)
		x0 = 0;
	if (x1 >= WIDTH)
		x1 = WIDTH - 1;
	while (x0 <= x1)
	{
		if (p->t1 > 0 && p->t1 < data->z_buffer[x0])
			draw_sprite_column(img, sprite_column(data, sprite, x0, geo));
		x0++;
	}
}
