/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:18:48 by maumonte          #+#    #+#             */
/*   Updated: 2026/08/24 13:35:43 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keyboard_event(int keyboard, t_data *data)
{
	if (keyboard == 65307)
	{
		cleanup(data);
		printf("You closed the window.\n");
		exit(0);
	}
	if (keyboard == W)
		data->player.move_up = 1;
	else if (keyboard == S)
		data->player.move_down = 1;
	else if (keyboard == A)
		data->player.move_left = 1;
	else if (keyboard == D)
		data->player.move_right = 1;
	else if (keyboard == LEFT)
		data->player.look_left = 1;
	else if (keyboard == RIGHT)
		data->player.look_right = 1;
	return (keyboard);
}

int	key_release(int keyboard, t_data *data)
{
	if (keyboard == W)
		data->player.move_up = 0;
	else if (keyboard == S)
		data->player.move_down = 0;
	else if (keyboard == A)
		data->player.move_left = 0;
	else if (keyboard == D)
		data->player.move_right = 0;
	else if (keyboard == LEFT)
		data->player.look_left = 0;
	else if (keyboard == RIGHT)
		data->player.look_right = 0;
	return (keyboard);
}

int	close_x(t_data *data)
{
	cleanup(data);
	exit(0);
}
