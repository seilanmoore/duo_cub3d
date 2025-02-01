/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:51:57 by smoore-a          #+#    #+#             */
/*   Updated: 2025/02/01 11:17:37 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_forward(t_data *data)
{
	if (data->a_map \
	[(int)(data->player.pos_x + data->player.dir_x * data->player.move_speed)] \
	[(int)(data->player.pos_y)] == 0)
		data->player.pos_x += data->player.dir_x * data->player.move_speed;
	if (data->a_map \
	[(int)(data->player.pos_x)] \
	[(int)(data->player.pos_y + data->player.dir_y * data->player.move_speed)] \
	== 0)
		data->player.pos_y += data->player.dir_y * data->player.move_speed;
}

void	move_backwards(t_data *data)
{
	if (data->a_map \
	[(int)(data->player.pos_x - data->player.dir_x * data->player.move_speed)] \
	[(int)(data->player.pos_y)] == 0)
		data->player.pos_x -= data->player.dir_x * data->player.move_speed;
	if (data->a_map \
	[(int)(data->player.pos_x)] \
	[(int)(data->player.pos_y - data->player.dir_y * data->player.move_speed)] \
	== 0)
		data->player.pos_y -= data->player.dir_y * data->player.move_speed;
}

void	move_to_left(t_data *data)
{
	if (data->a_map \
	[(int)(data->player.pos_x + data->player.dir_y * data->player.move_speed)] \
	[(int)(data->player.pos_y)] == 0)
		data->player.pos_x += data->player.dir_y * data->player.move_speed;
	if (data->a_map \
	[(int)(data->player.pos_x)] \
	[(int)(data->player.pos_y - data->player.dir_x * data->player.move_speed)] \
	== 0)
		data->player.pos_y -= data->player.dir_x * data->player.move_speed;
}

void	move_to_right(t_data *data)
{
	if (data->a_map \
	[(int)(data->player.pos_x - data->player.dir_y * data->player.move_speed)] \
	[(int)(data->player.pos_y)] == 0)
		data->player.pos_x -= data->player.dir_y * data->player.move_speed;
	if (data->a_map \
	[(int)(data->player.pos_x)] \
	[(int)(data->player.pos_y + data->player.dir_x * data->player.move_speed)] \
	== 0)
		data->player.pos_y += data->player.dir_x * data->player.move_speed;
}

void	handle_movement(t_data *data)
{
	if (data->key.w)
		move_forward(data);
	if (data->key.s)
		move_backwards(data);
	if (data->key.a)
		move_to_left(data);
	if (data->key.d)
		move_to_right(data);
	if (data->key.left)
		rotate_player_left(data);
	if (data->key.right)
		rotate_player_right(data);
}
