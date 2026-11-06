/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static unsigned int	get_pixel_clamped(t_image *img, int x, int y)
{
	char	*src;

	if (x < 0)
		x = 0;
	if (x >= img->width)
		x = img->width - 1;
	if (y < 0)
		y = 0;
	if (y >= img->height)
		y = img->height - 1;
	src = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)src);
}

static unsigned int	lerp_channel(t_bilin b, int shift)
{
	unsigned int	a;
	unsigned int	c;

	a = (((b.c00 >> shift) & 0xff) * (1 - b.fu)
			+ ((b.c10 >> shift) & 0xff) * b.fu) * (1 - b.fv)
		+ (((b.c01 >> shift) & 0xff) * (1 - b.fu)
			+ ((b.c11 >> shift) & 0xff) * b.fu) * b.fv;
	c = (unsigned int)a;
	return (c);
}

static unsigned int	sample_bilinear(t_image *img, float sx, float sy)
{
	t_bilin	b;
	int		x0;
	int		y0;

	x0 = (int)sx;
	y0 = (int)sy;
	b.fu = sx - x0;
	b.fv = sy - y0;
	b.c00 = get_pixel_clamped(img, x0, y0);
	b.c10 = get_pixel_clamped(img, x0 + 1, y0);
	b.c01 = get_pixel_clamped(img, x0, y0 + 1);
	b.c11 = get_pixel_clamped(img, x0 + 1, y0 + 1);
	if (b.c00 == TX_TRANSPARENT || b.c10 == TX_TRANSPARENT
		|| b.c01 == TX_TRANSPARENT || b.c11 == TX_TRANSPARENT)
		return (TX_TRANSPARENT);
	return ((lerp_channel(b, 16) << 16) | (lerp_channel(b, 8) << 8)
		| lerp_channel(b, 0));
}

static void	fill_texture(t_image *new, t_image *tex)
{
	int		x;
	int		y;
	float	sx;
	float	sy;

	y = 0;
	while (y < TEX_SIZE)
	{
		x = 0;
		while (x < TEX_SIZE)
		{
			sx = (x + 0.5f) * tex->width / TEX_SIZE - 0.5f;
			sy = (y + 0.5f) * tex->height / TEX_SIZE - 0.5f;
			my_mlx_pixel_put(new, x, y,
				sample_bilinear(tex, sx, sy));
			x++;
		}
		y++;
	}
}

void	resize_to_tex(t_data *data, t_image *tex)
{
	t_image	new;

	if (tex->width == TEX_SIZE && tex->height == TEX_SIZE)
		return ;
	new.img = mlx_new_image(data->data.mlx, TEX_SIZE, TEX_SIZE);
	if (!new.img)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nfalha ao redimensionar textura!",
			2);
		(cleanup(data), exit(1));
	}
	new.addr = mlx_get_data_addr(new.img, &new.bits_per_pixel,
			&new.size_line, &new.endian);
	new.width = TEX_SIZE;
	new.height = TEX_SIZE;
	fill_texture(&new, tex);
	mlx_destroy_image(data->data.mlx, tex->img);
	tex->img = new.img;
	tex->addr = new.addr;
	tex->bits_per_pixel = new.bits_per_pixel;
	tex->size_line = new.size_line;
	tex->endian = new.endian;
	tex->width = TEX_SIZE;
	tex->height = TEX_SIZE;
}
