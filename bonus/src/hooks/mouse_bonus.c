/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:00:00 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/22 17:00:00 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	rotate_player(t_data *data, int delta)
{
	data->player.angle += delta * MOUSE_SENSITIVITY;
	update_camera_vectors(&data->player);
}

int	move_mouse(int x, int y, t_data *data)
{
	int	center_x;

	(void)y;
	center_x = WIDTH / 2;
	if (x != center_x)
	{
		rotate_player(data, x - center_x);
		data->mini.mouse_moved = 1;
		mlx_mouse_move(data->data.mlx, data->data.win, center_x, HEIGHT / 2);
	}
	return (0);
}
