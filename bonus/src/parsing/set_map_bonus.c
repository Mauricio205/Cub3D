/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:46:19 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:15:14 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (0);
	return (1);
}

void	set_map(t_data *map, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && check_line(line + 3))
		save_no(map, line);
	else if (!ft_strncmp(line, "SO ", 3) && check_line(line + 3))
		save_so(map, line);
	else if (!ft_strncmp(line, "WE ", 3) && check_line(line + 3))
		save_we(map, line);
	else if (!ft_strncmp(line, "EA ", 3) && check_line(line + 3))
		save_ea(map, line);
	else if (!ft_strncmp(line, "F ", 2) && check_line(line + 2))
		save_floor(map, line);
	else if (!ft_strncmp(line, "C ", 2) && check_line(line + 2))
		save_ceiling(map, line);
	else
		save_map_line(map, line);
}
