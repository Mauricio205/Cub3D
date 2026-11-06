/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mipmap_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:00:00 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/17 12:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_levels(int w, int h)
{
	int	n;

	n = 0;
	while (w > 1 && h > 1)
	{
		w /= 2;
		h /= 2;
		n++;
	}
	return (n);
}

static void	fill_mipmaps(t_image *list, t_image *base, int n)
{
	int	k;
	int	nw;
	int	nh;

	nw = base->width;
	nh = base->height;
	k = 0;
	while (k < n)
	{
		nw /= 2;
		nh /= 2;
		list[k] = down_scale(*base, nw, nh);
		*base = list[k];
		k++;
	}
}

void	build_mipmaps(t_image *img)
{
	t_image	*list;
	t_image	base;
	int		n;

	n = count_levels(img->width, img->height);
	list = malloc((n + 1) * sizeof(t_image));
	if (!list)
		return ;
	base = *img;
	fill_mipmaps(list, &base, n);
	list[n].addr = NULL;
	list[n].width = 0;
	list[n].height = 0;
	list[n].mips = NULL;
	img->mips = list;
}
