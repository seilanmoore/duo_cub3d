/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:01:33 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/28 14:14:30 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	extract_ceiling_color(t_parse *to_parse, char **content)
{
	char	*element;

	element = seek_element(content, "C ", &(to_parse->row_b4_map));
	if (element)
		element++;
	if (!element)
		return (to_parse->ceiling_color[0] = -1, -1);
	else
		to_parse->ceiling_color[0] = ft_atoi(element);
	element = ft_strchr(element, ',');
	if (element)
		element++;
	if (!element)
		return (to_parse->ceiling_color[1] = -1, -1);
	else
		to_parse->ceiling_color[1] = ft_atoi(element);
	element = ft_strchr(element, ',');
	if (element)
		element++;
	if (!element)
		return (to_parse->ceiling_color[2] = -1, -1);
	else
		to_parse->ceiling_color[2] = ft_atoi(element);
	return (0);
}

static int	extract_floor_color(t_parse *to_parse, char **content)
{
	char	*element;

	element = seek_element(content, "F ", &(to_parse->row_b4_map));
	if (element)
		element++;
	if (!element)
		return (to_parse->floor_color[0] = -1, -1);
	else
		to_parse->floor_color[0] = ft_atoi(element);
	element = ft_strchr(element, ',');
	if (element)
		element++;
	if (!element)
		return (to_parse->floor_color[1] = -1, -1);
	else
		to_parse->floor_color[1] = ft_atoi(element);
	element = ft_strchr(element, ',');
	if (element)
		element++;
	if (!element)
		return (to_parse->floor_color[2] = -1, -1);
	else
		to_parse->floor_color[2] = ft_atoi(element);
	return (0);
}

static void	valid_color(t_data *data, t_parse *to_parse)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		data->floor_color[i] = to_parse->floor_color[i];
		data->ceiling_color[i] = to_parse->ceiling_color[i];
		if (data->floor_color[i] < 0 || data->floor_color[i] > 255 || \
		data->ceiling_color[i] < 0 || data->ceiling_color[i] > 255)
		{
			free_parse(to_parse);
			clean_exit(data, "bad color", 1);
		}
	}
}

void	parse_colors(t_data *data, t_parse *to_parse)
{
	extract_floor_color(to_parse, to_parse->content);
	extract_ceiling_color(to_parse, to_parse->content);
	valid_color(data, to_parse);
}
