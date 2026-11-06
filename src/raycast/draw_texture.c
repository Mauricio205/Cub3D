/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:25:02 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	bilinear(t_bilin b)
{
	float	r;
	float	g;
	float	bl;

	r = ((b.c00 & 0xff) * (1 - b.fu) + (b.c10 & 0xff) * b.fu) * (1 - b.fv)
		+ ((b.c01 & 0xff) * (1 - b.fu) + (b.c11 & 0xff) * b.fu) * b.fv;
	g = (((b.c00 >> 8) & 0xff) * (1 - b.fu) + ((b.c10 >> 8) & 0xff) * b.fu)
		* (1 - b.fv) + (((b.c01 >> 8) & 0xff) * (1 - b.fu)
			+ ((b.c11 >> 8) & 0xff) * b.fu) * b.fv;
	bl = (((b.c00 >> 16) & 0xff) * (1 - b.fu) + ((b.c10 >> 16) & 0xff) * b.fu)
		* (1 - b.fv) + (((b.c01 >> 16) & 0xff) * (1 - b.fu)
			+ ((b.c11 >> 16) & 0xff) * b.fu) * b.fv;
	return (((unsigned int)r) | ((unsigned int)g << 8)
		| ((unsigned int)bl << 16));
}

static unsigned int	sample_line(t_sampler s, int ifv, float fv)
{
	t_bilin	b;

	b.c00 = *(unsigned int *)(s.tex->addr + (ifv * s.tex->size_line
				+ s.ifu * s.bpp));
	b.c10 = *(unsigned int *)(s.tex->addr + (ifv * s.tex->size_line
				+ (s.ifu + 1) * s.bpp));
	b.c01 = *(unsigned int *)(s.tex->addr + ((ifv + 1) * s.tex->size_line
				+ s.ifu * s.bpp));
	b.c11 = *(unsigned int *)(s.tex->addr + ((ifv + 1) * s.tex->size_line
				+ (s.ifu + 1) * s.bpp));
	b.fu = s.fu;
	b.fv = fv;
	return (bilinear(b));
}

static t_sampler	prepare_sampler(t_raycast ray, int x, float wall_x)
{
	t_sampler	s;
	t_image		*mip;
	float		u;

	mip = select_mip(ray.tex, ray.tex->height / (float)ray.line_height);
	s.tex = mip;
	s.x = x;
	s.bpp = mip->bits_per_pixel / 8;
	s.draw_start = ray.draw_start;
	s.draw_end = ray.draw_end;
	u = wall_x * (mip->width - 1.0f);
	s.ifu = (int)u;
	s.fu = u - s.ifu;
	if (s.ifu < 0)
		s.ifu = 0;
	if (s.ifu >= mip->width - 1)
		s.ifu = mip->width - 2;
	s.step = mip->height / (float)ray.line_height;
	s.tex_pos = (ray.draw_start - HEIGHT / 2 + ray.line_height / 2) * s.step;
	return (s);
}

static void	draw_wall(t_image *img, t_sampler s)
{
	int		y;
	int		ifv;
	float	v;
	float	fv;

	y = s.draw_start;
	while (y < s.draw_end)
	{
		v = s.tex_pos;
		ifv = (int)v;
		fv = v - ifv;
		if (ifv < 0)
			ifv = 0;
		if (ifv >= s.tex->height - 1)
			ifv = s.tex->height - 2;
		my_mlx_pixel_put(img, s.x, y, sample_line(s, ifv, fv));
		s.tex_pos += s.step;
		y++;
	}
}

void	insert_texture(t_image *img, t_raycast ray, int x, float wall_x)
{
	t_sampler	s;

	s = prepare_sampler(ray, x, wall_x);
	draw_wall(img, s);
}
