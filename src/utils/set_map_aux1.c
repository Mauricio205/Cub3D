/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_aux1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:01:17 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 12:47:04 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_no(t_data *map, char *line)
{
	char		*l;
	static int	x;

	x++;
	if (x != 1)
	{
		clean_file(map->data.fd);
		ft_putendl_fd("\e[1;31mError\e[0m\nCoordenada duplicada!", 2);
		(free(line), cleanup(map), exit (1));
	}
	if (!map->check)
	{
		l = remove_reverse_space(line);
		map->texture.no = ft_strdup(l + 3);
		if (!is_valid_texture(map->texture.no))
		{
			clean_file(map->data.fd);
			ft_putendl_fd("\e[1;31mError\e[0m\nCoordenada inválida!", 2);
			(free(l), free(line), cleanup(map), exit (1));
		}
		free(l);
	}
}

void	save_so(t_data *map, char *line)
{
	char		*l;
	static int	x;

	x++;
	if (x != 1)
	{
		clean_file(map->data.fd);
		ft_putendl_fd("\e[1;31mError\e[0m\nCoordenada duplicada!", 2);
		(free(line), cleanup(map), exit (1));
	}
	if (!map->check)
	{
		l = remove_reverse_space(line);
		map->texture.so = ft_strdup(l + 3);
		if (!is_valid_texture(map->texture.so))
		{
			clean_file(map->data.fd);
			ft_putendl_fd("\e[1;31mError\e[0m\nCoordenada inválida!", 2);
			(free(l), free(line), cleanup(map), exit (1));
		}
		free(l);
	}
}

void	save_we(t_data *map, char *line)
{
	char		*l;
	static int	x;

	x++;
	if (x != 1)
	{
		clean_file(map->data.fd);
		ft_putendl_fd("\e[1;31mError\e[0m\nCoordenada duplicada!", 2);
		(free(line), cleanup(map), exit (1));
	}
	if (!map->check)
	{
		l = remove_reverse_space(line);
		map->texture.we = ft_strdup(l + 3);
		if (!is_valid_texture(map->texture.we))
		{
			clean_file(map->data.fd);
			ft_putendl_fd("\e[1;31mError\e[0m\nCoordenada inválida!", 2);
			(free(l), free(line), cleanup(map), exit (1));
		}
		free(l);
	}
}

void	save_ea(t_data *map, char *line)
{
	char		*l;
	static int	x;

	x++;
	if (x != 1)
	{
		clean_file(map->data.fd);
		ft_putendl_fd("\e[1;31mError\e[0m\nCoordenada duplicada!", 2);
		(free(line), cleanup(map), exit (1));
	}
	if (!map->check)
	{
		l = remove_reverse_space(line);
		map->texture.ea = ft_strdup(l + 3);
		if (!is_valid_texture(map->texture.ea))
		{
			clean_file(map->data.fd);
			ft_putendl_fd("\e[1;31mError\e[0m\nCoordenada inválida!", 2);
			(free(l), free(line), cleanup(map), exit (1));
		}
		free(l);
	}
}
