/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:03:51 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:14:46 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
