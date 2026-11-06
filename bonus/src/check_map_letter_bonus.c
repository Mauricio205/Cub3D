/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_letter_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:38:41 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:18:46 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	error_letter(t_data *map)
{
	ft_putendl_fd("\e[1;31mError\e[0m\ncaracter inválido!", 2);
	(cleanup(map), exit(1));
}

void	check_map_letter(t_data *map)
{
	char	c;

	while (map->map[map->data.x])
	{
		map->data.y = 0;
		while (map->map[map->data.x][map->data.y])
		{
			c = map->map[map->data.x][map->data.y];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				map->data.count_player++;
			else if (c != '1' && c != '0' && c != 'D' && c != 'd'
				&& c != 'M' && c != ' ' && c != '\n')
				error_letter(map);
			map->data.y++;
		}
		map->data.x++;
	}
	check_help(map);
}
