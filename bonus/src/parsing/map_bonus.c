/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:00:25 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:30:18 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	map_check(t_data *map)
{
	int	i;

	i = 0;
	while (map->data.line[i] == ' ')
		i++;
	if (map->data.line[i] == '1' || map->data.line[i] == '0')
		return (1);
	return (0);
}

void	map(char *av, t_data *map)
{
	count_line_map(map, av);
	map->data.fd = open(av, O_RDONLY);
	map->data.line = get_next_line(map->data.fd);
	check_extension_map(map, av);
	if (!av || map->data.fd < 0)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nmapa não encontrado!", 2);
		(cleanup(map), exit(1));
	}
	if (!map->data.line)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nficheiro vazio!", 2);
		(cleanup(map), exit(1));
	}
	map->map = ft_calloc(map->count_line + 1, sizeof(char *));
	while (map->data.line)
	{
		map->check = map_check(map);
		(set_map(map, map->data.line), free(map->data.line));
		map->data.line = get_next_line(map->data.fd);
	}
	(check_is_around_wall(map), close(map->data.fd));
}
