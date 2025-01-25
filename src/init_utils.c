/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:26:01 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/25 18:09:20 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdlib.h>

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
			if (ft_strchr("NSWE", data->map[i][j]))
			{
				player->pos_x = j + 0.5;
				player->pos_y = i + 0.5;
				player->init_coord = data->map[i][j];
				data->map[i][j] = '0';
			}
		}
	}
}

void	set_player_direction(t_player *player, int coord)
{
	if (coord == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (coord == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (coord == 'W')
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

/* void	set_plane(t_player *player)
{
	double	plane_len;

	plane_len = tan(FOV * M_PI / 360.0);
    player->plane_x = -player->dir_y * plane_len;
    player->plane_y = player->dir_x * plane_len;
} */

static void	allocate_map(t_data *data)
{
	int	i;

	data->a_map = malloc(data->map_width * sizeof(int *));
	if (!data->a_map)
	{
		data->map_width = 0;
		clean_exit(data, "malloc", 1);
	}
	i = -1;
	while (++i < data->map_width)
	{
		data->a_map[i] = (int *)malloc(data->map_height * sizeof(int));
		if (!(data->a_map[i]))
		{
			data->map_width = i;
			clean_exit(data, "malloc", 1);
		}
	}
}

void	convert_map(t_data *data)
{
	int	i;
	int	j;

	allocate_map(data);
	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (j < (int)ft_strlen(data->map[i]))
			{
				if (data->map[i][j] == '0')
					data->a_map[j][i] = 0;
				else
					data->a_map[j][i] = 1;
			}
			else
				data->a_map[j][i] = 1;
		}
	}
}
