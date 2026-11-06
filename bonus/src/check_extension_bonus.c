/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:54:51 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:18:54 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_extension_map(t_data *map, char *av)
{
	char	*p;

	p = ft_strrchr(av, '.');
	if (!av || is_hidden_file(av) || !p || ft_strncmp(p, ".cub", 5))
	{
		ft_putendl_fd("\e[1;31mError\e[0m\nmapa inválido(extensão)!", 2);
		cleanup(map);
		exit (1);
	}
}
