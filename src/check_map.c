/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:21:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/19 12:56:31 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	valid_char(int c)
{
	if (c == ' ')
		return (true);
	if (c == '0')
		return (true);
	if (c == '1')
		return (true);
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'W')
		return (true);
	if (c == 'E')
		return (true);
	return (false);
}

static void	check_characters(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!valid_char(map[i][j]))
				clean_exit(data, "bad map: bad character", 1);
		}
	}
}

static bool	is_outside(char **map, int i, int j)
{
	int	before_len;
	int	after_len;

	if (i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1])
		return (true);
	after_len = ft_strlen(map[i - 1]);
	before_len = ft_strlen(map[i + 1]);
	if (j >= before_len || j >= after_len)
		return (true);
	if (map[i + 1][j] == ' ' || \
	map[i - 1][j] == ' ' || \
	map[i][j + 1] == ' ' || \
	map[i][j - 1] == ' ')
		return (true);
	return (false);
}

static void	check_wall(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != ' ' && \
			map[i][j] != '1' && \
			is_outside(map, i, j))
				clean_exit(data, "bad map: bad wall", 1);
		}
	}
}

void	check_map(t_data *data)
{
	check_characters(data);
	check_several_coord(data, data->map);
	check_wall(data);
}
