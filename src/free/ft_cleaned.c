/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:25:56 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:35:18 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_map(t_data *map)
{
	if (map->map)
		ft_free_map(map->map);
	if (map->texture.no)
		free(map->texture.no);
	if (map->texture.so)
		free(map->texture.so);
	if (map->texture.ea)
		free(map->texture.ea);
	if (map->texture.we)
		free(map->texture.we);
	if (map->line_check_floor)
		free(map->line_check_floor);
	if (map->line_check_ceilling)
		free(map->line_check_ceilling);
}

void	cleanup(t_data *map)
{
	clean_map(map);
	if (map->tex_no.img)
		mlx_destroy_image(map->data.mlx, map->tex_no.img);
	if (map->tex_so.img)
		mlx_destroy_image(map->data.mlx, map->tex_so.img);
	if (map->tex_we.img)
		mlx_destroy_image(map->data.mlx, map->tex_we.img);
	if (map->tex_ea.img)
		mlx_destroy_image(map->data.mlx, map->tex_ea.img);
	free_mipmaps(&map->tex_no);
	free_mipmaps(&map->tex_so);
	free_mipmaps(&map->tex_we);
	free_mipmaps(&map->tex_ea);
	if (map->data.win)
		mlx_destroy_window(map->data.mlx, map->data.win);
	if (map->data.mlx)
		mlx_destroy_display(map->data.mlx);
	if (map->data.mlx)
		free(map->data.mlx);
}
