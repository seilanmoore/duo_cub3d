/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjezzard <jjezzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:02:48 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/15 18:12:37 by jjezzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdbool.h>

static bool	seek_path_line(t_parse *to_parse, char **content)
{
	to_parse->no_path = seek_element(content, "NO ", &(to_parse->row_b4_map));
	to_parse->so_path = seek_element(content, "SO ", &(to_parse->row_b4_map));
	to_parse->we_path = seek_element(content, "WE ", &(to_parse->row_b4_map));
	to_parse->ea_path = seek_element(content, "EA ", &(to_parse->row_b4_map));
	if (!to_parse->no_path || !to_parse->so_path || \
	!to_parse->we_path || !to_parse->ea_path)
		return (false);
	return (true);
}

static void	extract_path(t_parse *to_parse)
{
	to_parse->no_path = ft_strnstr(\
		to_parse->no_path, "NO ", ft_strlen(to_parse->no_path)) + 3;
	to_parse->so_path = ft_strnstr(\
		to_parse->so_path, "SO ", ft_strlen(to_parse->so_path)) + 3;
	to_parse->we_path = ft_strnstr(\
		to_parse->we_path, "WE ", ft_strlen(to_parse->we_path)) + 3;
	to_parse->ea_path = ft_strnstr(\
		to_parse->ea_path, "EA ", ft_strlen(to_parse->ea_path)) + 3;
	to_parse->no_path = ft_strtrim(to_parse->no_path, " \n");
	to_parse->so_path = ft_strtrim(to_parse->so_path, " \n");
	to_parse->we_path = ft_strtrim(to_parse->we_path, " \n");
	to_parse->ea_path = ft_strtrim(to_parse->ea_path, " \n");
}

static bool	valid_texture(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		return (false);
	mlx_delete_texture(texture);
	return (true);
}

static void	load_textures(t_data *data, t_parse *to_parse)
{
	if (valid_texture(to_parse->no_path) && \
	valid_texture(to_parse->so_path) && \
	valid_texture(to_parse->we_path) && \
	valid_texture(to_parse->ea_path))
	{
		data->no_tex = mlx_load_png(to_parse->no_path);
		data->so_tex = mlx_load_png(to_parse->so_path);
		data->we_tex = mlx_load_png(to_parse->we_path);
		data->ea_tex = mlx_load_png(to_parse->ea_path);
	}
	else
	{
		free_parse(to_parse);
		exit(print_msg("mlx_load_png", errno));
	}
}

void	parse_textures(t_data *data, t_parse *to_parse)
{
	if (seek_path_line(to_parse, to_parse->content))
	{
		extract_path(to_parse);
		load_textures(data, to_parse);
	}
	else
	{
		free_array(&(to_parse->content));
		exit(print_msg("bad path", errno));
	}
}
