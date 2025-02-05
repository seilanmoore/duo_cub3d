/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_fps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:44:53 by smoore-a          #+#    #+#             */
/*   Updated: 2025/02/01 15:55:04 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	limit_fps(t_data *data)
{
	double		frame_delay;
	double		frame_time;
	t_timeval	tv;

	frame_delay = 1000.0 / FPS_LIMIT;
	data->old_time = data->time;
	gettimeofday(&tv, NULL);
	data->time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	while ((data->time - data->old_time) < frame_delay)
	{
		gettimeofday(&tv, NULL);
		data->time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	}
	frame_time = (data->time - data->old_time) / 1000.0;
	if (!write(1, "\rFPS: ", 6))
		clean_exit(data, "write", errno);
	ft_putnbr_fd((int)(1.0 / frame_time), 1);
	if (!write(1, " ", 1))
		clean_exit(data, "write", errno);
	data->player.move_speed = frame_time * (double)MOVE_SPEED;
	data->player.rot_speed = frame_time * (double)ROT_SPEED;
}
