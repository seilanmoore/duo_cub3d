/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:23:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/28 14:06:52 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	allocate_map(t_data *data)
{
	int	i;

	data->a_map = (int **)malloc(data->map_width * sizeof(int *));
	if (!data->a_map)
	{
		data->map_width = 0;
		clean_exit(data, "malloc: bad map allocation", 1);
	}
	i = -1;
	while (++i < data->map_width)
	{
		data->a_map[i] = (int *)malloc(data->map_height * sizeof(int));
		if (!(data->a_map[i]))
		{
			if (!i)
				free(data->a_map);
			data->map_width = i;
			clean_exit(data, "malloc: bad map allocation", 1);
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
