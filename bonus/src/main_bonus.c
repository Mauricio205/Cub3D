/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:38:41 by maumonte          #+#    #+#             */
/*   Updated: 2026/09/22 16:48:24 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_error(t_data *map)
{
	if (!map->data.mlx)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nfalha ao iniciar mlx!", 2);
		(cleanup(map), exit(1));
	}
	if (!map->texture.no || !map->texture.so
		|| !map->texture.we || !map->texture.ea)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\n", 2);
		ft_putendl_fd("falha na configuração do ficheiro!", 2);
		(cleanup(map), exit(1));
	}
	if (!map->line_check_floor || !map->line_check_ceilling)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\n", 2);
		ft_putendl_fd("falha na configuração do ficheiro!", 2);
		(cleanup(map), exit(1));
	}
}

static void	check_error_arg(int ac)
{
	if (ac != 2)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\npoucos/muitos argumentos!", 2);
		exit (1);
	}
}

static void	load_assets(t_data *data)
{
	init_sprites(data);
	data->data.mlx = mlx_init();
	check_error(data);
	load_textures(data);
	load_door_textures(data);
	load_sprite_frames(data);
}

static void	start_mlx(t_data *data)
{
	data->start_screen = 1;
	data->data.win = mlx_new_window(data->data.mlx, WIDTH, HEIGHT, "cub3D");
	mlx_loop_hook(data->data.mlx, game_loop, data);
	mlx_hook(data->data.win, 6, 1L << 6, move_mouse, data);
	mlx_hook(data->data.win, 2, 1L << 0, keyboard_event, data);
	mlx_hook(data->data.win, 3, 1L << 1, key_release, data);
	mlx_hook(data->data.win, 17, 0, close_x, data);
	mlx_loop(data->data.mlx);
}

int	main(int ac, char *av[])
{
	t_data	data;

	check_error_arg(ac);
	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&data.data, sizeof(t_mlx));
	map(av[1], &data);
	if (!data.check)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nmapa vazio!", 2);
		(cleanup(&data), exit(1));
	}
	check_map_letter(&data);
	init_player(&data);
	init_doors(&data);
	load_assets(&data);
	init_player_minimap(&data);
	start_mlx(&data);
	return (0);
}
