/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:02:48 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/28 13:31:31 by smoore-a         ###   ########.fr       */
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

static bool	valid_texture(t_data *data, char *path)
{
	t_img	texture;

	texture.img_ptr = mlx_xpm_file_to_image(\
		data->mlx, path, &(texture.width), &(texture.height));
	if (!texture.img_ptr)
		return (false);
	mlx_destroy_image(data->mlx, texture.img_ptr);
	return (true);
}

static void	load_textures(t_data *data, t_parse *to_parse)
{
	if (valid_texture(data, to_parse->no_path) && \
	valid_texture(data, to_parse->so_path) && \
	valid_texture(data, to_parse->we_path) && \
	valid_texture(data, to_parse->ea_path))
	{
		data->tex_img[0].img_ptr = mlx_xpm_file_to_image(
				data->mlx, to_parse->no_path, \
				&(data->tex_img[0].width), &(data->tex_img[0].height));
		data->tex_img[1].img_ptr = mlx_xpm_file_to_image(
				data->mlx, to_parse->so_path, \
				&(data->tex_img[1].width), &(data->tex_img[1].height));
		data->tex_img[2].img_ptr = mlx_xpm_file_to_image(
				data->mlx, to_parse->we_path, \
				&(data->tex_img[2].width), &(data->tex_img[2].height));
		data->tex_img[3].img_ptr = mlx_xpm_file_to_image(
				data->mlx, to_parse->ea_path, \
				&(data->tex_img[3].width), &(data->tex_img[3].height));
	}
	else
	{
		free_parse(to_parse);
		clean_exit(data, "mlx_xpm_file_to_image", 1);
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
		clean_exit(data, "bad path element", 1);
	}
}
