/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:23:01 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/28 11:23:27 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_player_position(t_data *data, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == data->init_dir)
			{
				player->pos_x = j + 0.5;
				player->pos_y = i + 0.5;
				data->map[i][j] = '0';
			}
		}
	}
}

void	set_player_direction(t_player *player, int direction)
{
	if (direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	else
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
}

void	set_plane(t_player *player)
{
	if (player->dir_x == 0 && player->dir_y < 0)
	{
		player->plane_x = (double)FOV / 100.0;
		player->plane_y = 0;
	}
	else if (player->dir_x == 0 && player->dir_y > 0)
	{
		player->plane_x = -(double)FOV / 100.0;
		player->plane_y = 0;
	}
	else if (player->dir_x < 0 && player->dir_y == 0)
	{
		player->plane_x = 0;
		player->plane_y = -(double)FOV / 100.0;
	}
	else
	{
		player->plane_x = 0;
		player->plane_y = (double)FOV / 100.0;
	}
}
