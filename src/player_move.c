/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:51:57 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/26 14:37:44 by smoore-a         ###   ########.fr       */
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
