/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:27:22 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/28 14:09:24 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	increase_set_dir(t_data *data, int c, int *init_dir)
{
	if (c == 'N')
	{
		init_dir[0]++;
		data->init_dir = 'N';
	}
	else if (c == 'S')
	{
		init_dir[1]++;
		data->init_dir = 'S';
	}
	else if (c == 'W')
	{
		init_dir[2]++;
		data->init_dir = 'W';
	}
	else if (c == 'E')
	{
		init_dir[3]++;
		data->init_dir = 'E';
	}
}

void	check_several_dir(t_data *data, char **map)
{
	int	init_dir[4];
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
		init_dir[i] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			increase_set_dir(data, map[i][j], init_dir);
	}
	if ((init_dir[0] + init_dir[1] + init_dir[2] + init_dir[3]) != 1)
		clean_exit(data, "bad map: bad direction", 1);
}
