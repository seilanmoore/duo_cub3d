/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:51:57 by smoore-a          #+#    #+#             */
/*   Updated: 2025/02/05 20:27:15 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_axis(t_data *data, double delta, int is_x_axis)
{
	double	new_pos;
	int		map_coord;
	double	*current_pos;

	if (is_x_axis)
		current_pos = &data->player.pos_x;
	else
		current_pos = &data->player.pos_y;
	new_pos = *current_pos + delta;
	map_coord = (int)new_pos;
	if (is_x_axis && (map_coord < 0 || map_coord >= data->map_width))
		return ;
	if (!is_x_axis && (map_coord < 0 || map_coord >= data->map_height))
		return ;
	if (is_x_axis && !check_collision(data, new_pos, data->player.pos_y)
		&& data->a_map[map_coord][(int)data->player.pos_y] == 0)
		*current_pos = new_pos;
	else if (!is_x_axis && !check_collision(data, data->player.pos_x, new_pos)
		&& data->a_map[(int)data->player.pos_x][map_coord] == 0)
		*current_pos = new_pos;
}

void	move_forward(t_data *data)
{
	double	speed;

	speed = data->player.move_speed;
	move_axis(data, data->player.dir_x * speed, 1);
	move_axis(data, data->player.dir_y * speed, 0);
}

void	move_backwards(t_data *data)
{
	double	speed;

	speed = data->player.move_speed;
	move_axis(data, -data->player.dir_x * speed, 1);
	move_axis(data, -data->player.dir_y * speed, 0);
}

void	move_to_left(t_data *data)
{
	double	speed;

	speed = data->player.move_speed;
	move_axis(data, data->player.dir_y * speed, 1);
	move_axis(data, -data->player.dir_x * speed, 0);
}

void	move_to_right(t_data *data)
{
	double	speed;

	speed = data->player.move_speed;
	move_axis(data, -data->player.dir_y * speed, 1);
	move_axis(data, data->player.dir_x * speed, 0);
}

/*
int	check_collision(t_data *data, double x, double y)
{
	double	radius;

	radius = 0.1;
	if (data->a_map[(int)x][(int)(y - radius)] == 1)
		return (1);
	if (data->a_map[(int)x][(int)(y + radius)] == 1)
		return (1);
	if (data->a_map[(int)(x - radius)][(int)y] == 1)
		return (1);
	if (data->a_map[(int)(x + radius)][(int)y] == 1)
		return (1);
	if (data->a_map[(int)(x - radius)][(int)(y - radius)] == 1)
		return (1);
	if (data->a_map[(int)(x + radius)][(int)(y - radius)] == 1)
		return (1);
	if (data->a_map[(int)(x - radius)][(int)(y + radius)] == 1)
		return (1);
	if (data->a_map[(int)(x + radius)][(int)(y + radius)] == 1)
		return (1);
	return (0);
}

void	move_forward(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = (int)(data->player.pos_x + \
		data->player.dir_x * data->player.move_speed);
	new_y = (int)(data->player.pos_y + \
		data->player.dir_y * data->player.move_speed);
	if (new_x >= 0 && new_x < data->map_width)
	{
		if (check_collision(data, \
		data->player.pos_x + data->player.dir_x * data->player.move_speed, \
		data->player.pos_y))
			;
		else if (data->a_map[new_x][(int)(data->player.pos_y)] == 0)
			data->player.pos_x += data->player.dir_x * data->player.move_speed;
	}
	if (new_y >= 0 && new_y < data->map_height)
	{
		if (check_collision(data, \
		data->player.pos_x, \
		data->player.pos_y + data->player.dir_y * data->player.move_speed))
			;
		else if (new_y >= 0 && new_y < data->map_height && \
		data->a_map[(int)(data->player.pos_x)][new_y] == 0)
			data->player.pos_y += data->player.dir_y * data->player.move_speed;
	}
}

void	move_backwards(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = (int)(data->player.pos_x - \
		data->player.dir_x * data->player.move_speed);
	new_y = (int)(data->player.pos_y - \
		data->player.dir_y * data->player.move_speed);
	if (new_x >= 0 && new_x < data->map_width && \
	data->a_map[new_x][(int)(data->player.pos_y)] == 0)
		data->player.pos_x -= data->player.dir_x * data->player.move_speed;
	if (new_y >= 0 && new_y < data->map_height && \
	data->a_map[(int)(data->player.pos_x)][new_y] == 0)
		data->player.pos_y -= data->player.dir_y * data->player.move_speed;
}

void	move_to_left(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = (int)(data->player.pos_x + \
		data->player.dir_y * data->player.move_speed);
	new_y = (int)(data->player.pos_y - \
		data->player.dir_x * data->player.move_speed);
	if (new_x >= 0 && new_x < data->map_width && \
	data->a_map[new_x][(int)(data->player.pos_y)] == 0)
		data->player.pos_x += data->player.dir_y * data->player.move_speed;
	if (new_y >= 0 && new_y < data->map_height && \
	data->a_map[(int)(data->player.pos_x)][new_y] == 0)
		data->player.pos_y -= data->player.dir_x * data->player.move_speed;
}

void	move_to_right(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = (int)(data->player.pos_x - \
		data->player.dir_y * data->player.move_speed);
	new_y = (int)(data->player.pos_y + \
		data->player.dir_x * data->player.move_speed);
	if (new_x >= 0 && new_x < data->map_width && \
	data->a_map[new_x][(int)(data->player.pos_y)] == 0)
		data->player.pos_x -= data->player.dir_y * data->player.move_speed;
	if (new_y >= 0 && new_y < data->map_height && \
	data->a_map[(int)(data->player.pos_x)][new_y] == 0)
		data->player.pos_y += data->player.dir_x * data->player.move_speed;
}
*/
