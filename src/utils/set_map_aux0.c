/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_aux0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 10:59:46 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 12:46:45 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	message_error_rgb(t_data *map, char **mat, char *line, int fd)
{
	clean_file(fd);
	ft_putendl_fd("\e[1;31mError\e[0m\nRGB inválido!", 2);
	(free(line), ft_free_map(mat), cleanup(map), exit (1));
}

static	int	count_quote(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	if (j > 2)
		return (0);
	return (1);
}

void	save_floor(t_data *map, char *line)
{
	char		**mat;
	char		*l;
	static int	x;

	x++;
	if (x != 1)
		(ft_putendl_fd("\e[1;31mError\e[0m\nRGB duplicada!", 2),
			clean_file(map->data.fd), (free(line), cleanup(map), exit (1)));
	if (!map->check)
	{
		map->line_check_floor = ft_strdup(line);
		l = remove_reverse_space(line);
		mat = ft_split(l + 2, ',');
		map->floor.r = ft_atoi(mat[0]);
		map->floor.g = ft_atoi(mat[1]);
		map->floor.b = ft_atoi(mat[2]);
		if (map->floor.r > 255 || map->floor.g > 255
			|| map->floor.b > 255)
			(free(l), message_error_rgb(map, mat, line, map->data.fd));
		if (!is_valid_color(mat))
			(free(l), message_error_rgb(map, mat, line, map->data.fd));
		if (!count_quote(line))
			(free(l), message_error_rgb(map, mat, line, map->data.fd));
		(free(l), ft_free_map(mat));
	}
}

void	save_ceiling(t_data *map, char *line)
{
	char		**mat;
	char		*l;
	static int	x;

	x++;
	if (x != 1)
		(ft_putendl_fd("\e[1;31mError\e[0m\nRGB duplicada!", 2),
			clean_file(map->data.fd), (free(line), cleanup(map), exit (1)));
	if (!map->check)
	{
		map->line_check_ceilling = ft_strdup(line);
		l = remove_reverse_space(line);
		mat = ft_split(l + 2, ',');
		map->ceiling.r = ft_atoi(mat[0]);
		map->ceiling.g = ft_atoi(mat[1]);
		map->ceiling.b = ft_atoi(mat[2]);
		if (map->ceiling.r > 255 || map->ceiling.g > 255
			|| map->ceiling.b > 255)
			(free(l), message_error_rgb(map, mat, line, map->data.fd));
		if (!is_valid_color(mat))
			(free(l), message_error_rgb(map, mat, line, map->data.fd));
		if (!count_quote(line))
			(free(l), message_error_rgb(map, mat, line, map->data.fd));
		(free(l), ft_free_map(mat));
	}
}

void	save_map_line(t_data *map, char *line)
{
	static int	x;

	if (x && line[0] == '\n')
	{
		clean_file(map->data.fd);
		ft_putendl_fd("\e[1;31mError\e[0m\nMapa contém quebra!", 2);
		(free(line), cleanup(map), exit (1));
	}
	else if (map->check)
	{
		x++;
		map->map[map->index_map] = ft_strdup(line);
		map->index_map++;
	}
	else if (!check_space_and_break(line))
	{
		clean_file(map->data.fd);
		ft_putendl_fd("\e[1;31mError\e[0m\n", 2);
		ft_putendl_fd("falha na configuração do ficheiro!", 2);
		(free(line), cleanup(map), exit (1));
	}
}
