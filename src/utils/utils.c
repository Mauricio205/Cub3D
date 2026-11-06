/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:56:44 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 12:47:24 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line [i] == '0')
		return (1);
	return (0);
}

void	count_line_map(t_data *map, char *av)
{
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	map->count_line = 0;
	while (line)
	{
		if (is_map_line(line))
			map->count_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	clean_file(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
}

int	check_space_and_break(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\n' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	check_help(t_data *map)
{
	if (!map->data.count_player)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nnenhum jogador no mapa!", 2);
		(cleanup(map), exit(1));
	}
	else if (map->data.count_player > 1)
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nmais de um Player!", 2);
		(cleanup(map), exit(1));
	}
}
