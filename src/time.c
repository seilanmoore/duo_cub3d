/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:44:53 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/25 22:52:56 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <sys/time.h>

void	set_time(t_data *data)
{
	double		frame_time;
	t_timeval	tv;

	data->old_time = data->time;
	gettimeofday(&tv, NULL);
	data->time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	frame_time = (data->time - data->old_time) / 1000.0;
	data->player.move_speed = frame_time * (double)MOVE_SPEED;
	data->player.rot_speed = frame_time * (double)ROT_SPEED;
}
