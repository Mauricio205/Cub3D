/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:38:41 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:26:57 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_error(t_data *map)
{
	if (!map->data.mlx)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nfalha ao iniciar mlx!", 2);
		(cleanup(map), exit(1));
	}
	if (!map->texture.no || !map->texture.so || !map->texture.we
		|| !map->texture.ea)
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
		exit(1);
	}
}

static void	error_letter(t_data *map)
{
	ft_putendl_fd("\e[1;31mError\e[0m\ncaracter inválido!", 2);
	(cleanup(map), exit(1));
}

static void	check_map_letter(t_data *map)
{
	while (map->map[map->data.x])
	{
		map->data.y = 0;
		while (map->map[map->data.x][map->data.y])
		{
			if (map->map[map->data.x][map->data.y] == 'N')
				map->data.count_player++;
			else if (map->map[map->data.x][map->data.y] == 'S')
				map->data.count_player++;
			else if (map->map[map->data.x][map->data.y] == 'E')
				map->data.count_player++;
			else if (map->map[map->data.x][map->data.y] == 'W')
				map->data.count_player++;
			else if (map->map[map->data.x][map->data.y] == '1'
				|| map->map[map->data.x][map->data.y] == '0'
				|| map->map[map->data.x][map->data.y] == ' '
				|| map->map[map->data.x][map->data.y] == '\n')
				;
			else
				error_letter(map);
			map->data.y++;
		}
		map->data.x++;
	}
	check_help(map);
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
	data.data.mlx = mlx_init();
	check_error(&data);
	load_textures(&data);
	data.data.win = mlx_new_window(data.data.mlx, WIDTH, HEIGHT, "cub3D");
	mlx_loop_hook(data.data.mlx, game_loop, &data);
	mlx_hook(data.data.win, 2, 1L << 0, keyboard_event, &data);
	mlx_hook(data.data.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.data.win, 17, 0, close_x, &data);
	mlx_loop(data.data.mlx);
	return (0);
}
