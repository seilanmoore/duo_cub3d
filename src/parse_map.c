/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:55:25 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/18 12:22:51 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	count_row(char **map, t_parse *to_parse, t_data *data)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], '1') || ft_strchr(map[i], '0') || \
		ft_strchr(map[i], 'N') || ft_strchr(map[i], 'S') || \
		ft_strchr(map[i], 'W') || ft_strchr(map[i], 'E'))
			i++;
		else
			break ;
	}
	if (i < 3)
	{
		free_parse(to_parse);
		clean_exit(data, "bad map: few rows", 1);
	}
	return (i);
}

static void	extract_map(t_data *data, t_parse *to_parse)
{
	int	row;
	int	i;

	to_parse->map = seek_map(&(to_parse->content[to_parse->row_b4_map + 1]));
	if (!to_parse->map)
	{
		free_parse(to_parse);
		clean_exit(data, "bad map: no map", 1);
	}
	row = count_row(to_parse->map, to_parse, data);
	data->map = malloc((row + 1) * sizeof(char *));
	i = -1;
	while (++i < row)
	{
		data->map[i] = ft_strtrim(to_parse->map[i], "\n");
		if (!(data->map[i]))
		{
			free_parse(to_parse);
			clean_exit(data, "ft_strtrim", 1);
		}
	}
	data->map[i] = NULL;
}

void	parse_map(t_data *data, t_parse *to_parse)
{
	extract_map(data, to_parse);
	free_parse(to_parse);
	check_map(data);
}
