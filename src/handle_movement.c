/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:24:04 by smoore-a          #+#    #+#             */
/*   Updated: 2025/02/05 20:24:49 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_collision(t_data *data, double x, double y)
{
	const double	radius = 0.1;
	const double	offsets[8][2] = {
	{0, -radius}, {0, radius},
	{-radius, 0}, {radius, 0},
	{-radius, -radius}, {radius, -radius},
	{-radius, radius}, {radius, radius}
	};
	int				map_x;
	int				map_y;
	int				i;

	i = -1;
	while (++i < 8)
	{
		map_x = (int)(x + offsets[i][0]);
		map_y = (int)(y + offsets[i][1]);
		if (map_x < 0 || map_x >= data->map_width
			|| map_y < 0 || map_y >= data->map_height)
			return (1);
		if (data->a_map[map_x][map_y] == 1)
			return (1);
	}
	return (0);
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
