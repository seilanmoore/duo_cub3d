/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:21:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/13 18:42:57 by smoore-a         ###   ########.fr       */
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
			{
				cleanup(data);
				exit(print_msg("bad map: bad character", errno));
			}
		}
	}
}

static bool	is_outside(char **map, int i, int j)
{
	int	len;

	if (i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1])
		return (true);
	len = ft_strlen(map[i + 1]);
	if (j > len)
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
			{
				cleanup(data);
				exit(print_msg("bad map: bad wall", errno));
			}
		}
	}
}

void	check_map(t_data *data)
{
	check_characters(data);
	check_several_coord(data, data->map);
	check_wall(data);
}
