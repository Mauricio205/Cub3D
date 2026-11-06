/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaned_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:25:56 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:14:42 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	free_doors(t_data *map)
{
	t_door	*door;
	t_door	*next;

	door = map->doors;
	while (door)
	{
		next = door->next;
		free(door);
		door = next;
	}
	map->doors = NULL;
}

static void	free_wall_textures(t_data *map)
{
	free_mipmaps(&map->tex_no);
	free_mipmaps(&map->tex_so);
	free_mipmaps(&map->tex_we);
	free_mipmaps(&map->tex_ea);
	if (map->tex_no.img)
		mlx_destroy_image(map->data.mlx, map->tex_no.img);
	if (map->tex_so.img)
		mlx_destroy_image(map->data.mlx, map->tex_so.img);
	if (map->tex_we.img)
		mlx_destroy_image(map->data.mlx, map->tex_we.img);
	if (map->tex_ea.img)
		mlx_destroy_image(map->data.mlx, map->tex_ea.img);
}

static void	free_door_textures(t_data *map)
{
	int	i;

	i = 0;
	while (i < DOOR_FRAMES)
	{
		if (map->tex_door[i].img)
			mlx_destroy_image(map->data.mlx, map->tex_door[i].img);
		i++;
	}
}

void	cleanup(t_data *map)
{
	clean_map(map);
	free_doors(map);
	free_sprites(map);
	cover_image_delete(map);
	if (map->mini.player_img)
		mlx_destroy_image(map->data.mlx, map->mini.player_img);
	if (map->game_over_loaded && map->game_over_tex.img)
		mlx_destroy_image(map->data.mlx, map->game_over_tex.img);
	free_wall_textures(map);
	free_door_textures(map);
	if (map->data.win)
		mlx_destroy_window(map->data.mlx, map->data.win);
	if (map->data.mlx)
		mlx_destroy_display(map->data.mlx);
	if (map->data.mlx)
		free(map->data.mlx);
}
