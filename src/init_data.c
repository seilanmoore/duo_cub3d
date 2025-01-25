/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:25:41 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/25 20:05:34 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_settings(t_data *data)
{
	data->width = (double)WIDTH;
	data->height = (double)HEIGHT;
}

static void	init_player(t_data *data)
{
	set_player_position(data, &(data->player));
	set_player_direction(&(data->player), data->player.init_coord);
	set_plane(&(data->player));
}

static void	init_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if ((j + 1) > data->map_width)
				data->map_width = j + 1;
		}
		if ((i + 1) > data->map_height)
			data->map_height = i + 1;
	}
	convert_map(data);
}

void	init_data(t_data *data)
{
	init_settings(data);
	init_player(data);
	init_map(data);
	int y = -1, x;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
			printf("%d", data->a_map[x][y]);
		printf("\n");
	}
	printf("Player pos_x: %f\nPlayer pos_y: %f\n", data->player.pos_x, data->player.pos_y);
}
