/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:23:33 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/26 14:54:51 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_player_left(t_data *data)
{
	double	cos_rot_speed;
	double	sin_rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	cos_rot_speed = cos(-data->player.rot_speed);
	sin_rot_speed = sin(-data->player.rot_speed);
	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos_rot_speed - \
		data->player.dir_y * sin_rot_speed;
	data->player.dir_y = old_dir_x * sin_rot_speed + \
		data->player.dir_y * cos_rot_speed;
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos_rot_speed - \
		data->player.plane_y * sin_rot_speed;
	data->player.plane_y = old_plane_x * sin_rot_speed + \
		data->player.plane_y * cos_rot_speed;
}

void	rotate_player_right(t_data *data)
{
	double	cos_rot_speed;
	double	sin_rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	cos_rot_speed = cos(data->player.rot_speed);
	sin_rot_speed = sin(data->player.rot_speed);
	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos_rot_speed - \
		data->player.dir_y * sin_rot_speed;
	data->player.dir_y = old_dir_x * sin_rot_speed + \
		data->player.dir_y * cos_rot_speed;
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos_rot_speed - \
		data->player.plane_y * sin_rot_speed;
	data->player.plane_y = old_plane_x * sin_rot_speed + \
		data->player.plane_y * cos_rot_speed;
}
