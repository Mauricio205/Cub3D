/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/22 17:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_hidden_file(char *path)
{
	char	*name;

	if (!path || !*path)
		return (0);
	name = ft_strrchr(path, '/');
	if (name)
		name++;
	else
		name = path;
	return (*name == '.');
}
