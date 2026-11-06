/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalexan <saalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:27:05 by saalexan          #+#    #+#             */
/*   Updated: 2026/09/22 16:10:46 by saalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_player(t_data *data)
{
	int		speed;
	float	angle_speed;

	speed = 3;
	angle_speed = 0.05;
	if (data->player.look_left)
		data->player.angle -= angle_speed;
	if (data->player.look_right)
		data->player.angle += angle_speed;
	if (data->player.angle >= 2 * PI)
		data->player.angle -= 2 * PI;
	if (data->player.angle < 0)
		data->player.angle += 2 * PI;
	update_camera_vectors(&data->player);
	move_player(data, data->player.dir_x, data->player.dir_y, speed);
}

static void	reset_player_data(t_data *data)
{
	data->player.move_left = 0;
	data->player.move_right = 0;
	data->player.move_up = 0;
	data->player.move_down = 0;
	data->player.look_left = 0;
	data->player.look_right = 0;
}

static void	render_frame(t_data *data, int animating)
{
	if (data->player.old_pos.x < 0 || animating || data->mini.mouse_moved
		|| data->player.look_left
		|| data->player.look_right || data->player.move_left
		|| data->player.move_right || data->player.move_up
		|| data->player.move_down)
	{
		update_player(data);
		data->player.old_pos = data->player.pos;
		render(data);
		reset_player_data(data);
		data->mini.mouse_moved = 0;
	}
}

int	game_loop(t_data *data)
{
	int	animating;

	if (data->start_screen)
	{
		show_cover(data);
		return (1);
	}
	if (data->game_over)
	{
		show_game_over(data);
		return (1);
	}
	animating = update_doors(data);
	animate_sprites(data);
	animating |= move_sprites(data);
	render_frame(data, animating);
	return (1);
}
