/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mipmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	avg4(unsigned int a, unsigned int b, unsigned int c,
	unsigned int d)
{
	int	r;
	int	g;
	int	bl;
	int	al;

	r = ((a & 0xff) + (b & 0xff) + (c & 0xff) + (d & 0xff)) / 4;
	g = (((a >> 8) & 0xff) + ((b >> 8) & 0xff)
			+ ((c >> 8) & 0xff) + ((d >> 8) & 0xff)) / 4;
	bl = (((a >> 16) & 0xff) + ((b >> 16) & 0xff)
			+ ((c >> 16) & 0xff) + ((d >> 16) & 0xff)) / 4;
	al = (((a >> 24) & 0xff) + ((b >> 24) & 0xff)
			+ ((c >> 24) & 0xff) + ((d >> 24) & 0xff)) / 4;
	return (((unsigned int)r) | ((unsigned int)g << 8)
		| ((unsigned int)bl << 16) | ((unsigned int)al << 24));
}

static unsigned int	sample_block(t_image *base, int i, int j, int bpp)
{
	unsigned int	*p;
	unsigned int	*bl;
	unsigned int	*br;

	p = (unsigned int *)(base->addr + ((2 * i) * base->size_line
				+ (2 * j) * bpp));
	bl = (unsigned int *)((char *)p + base->size_line);
	br = bl + 1;
	return (avg4(p[0], p[1], bl[0], br[0]));
}

static void	fill_level(t_image *base, t_image *next, int nw, int nh)
{
	int				i;
	int				j;
	unsigned int	*q;
	int				bpp;

	bpp = base->bits_per_pixel / 8;
	q = (unsigned int *)next->addr;
	i = 0;
	while (i < nh)
	{
		j = 0;
		while (j < nw)
		{
			q[i * nw + j] = sample_block(base, i, j, bpp);
			j++;
		}
		i++;
	}
}

t_image	down_scale(t_image base, int nw, int nh)
{
	t_image	next;

	next.addr = malloc(nw * nh * sizeof(unsigned int));
	if (!next.addr)
		return (next);
	next.width = nw;
	next.height = nh;
	next.size_line = nw * sizeof(unsigned int);
	next.bits_per_pixel = 32;
	next.endian = base.endian;
	next.is_malloc = 1;
	next.mips = NULL;
	next.img = NULL;
	fill_level(&base, &next, nw, nh);
	return (next);
}

void	free_mipmaps(t_image *img)
{
	int	i;

	if (!img->mips)
		return ;
	i = 0;
	while (img->mips[i].addr)
	{
		if (img->mips[i].is_malloc)
			free(img->mips[i].addr);
		i++;
	}
	free(img->mips);
	img->mips = NULL;
}
