/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:32:24 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/28 13:59:21 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	allocate_texture(t_data *data, int i, int x)
{
	data->tex[i] = (int **)malloc(\
		data->tex_img[i].width * sizeof(int *));
	if (!(data->tex[i]))
	{
		data->tex_img[i].width = 0;
		data->tex_img[++i].width = 0;
		clean_exit(data, "malloc: bad texture allocation", 1);
	}
	while (++x < data->tex_img[i].width)
	{
		data->tex[i][x] = (int *)malloc(\
			data->tex_img[i].height * sizeof(int));
		if (!(data->tex[i][x]))
		{
			if (!x)
				free(data->tex[i]);
			data->tex_img[i].width = x;
			data->tex_img[++i].width = 0;
			clean_exit(data, "malloc: bad texture allocation", 1);
		}
	}
}

static void	allocate_textures(t_data *data)
{
	int	i;
	int	x;

	x = -1;
	i = -1;
	while (++i < 4)
		allocate_texture(data, i, x);
}

void	image_to_array(t_data *data)
{
	t_img	*texture;
	int		i;
	int		x;
	int		y;

	allocate_textures(data);
	i = -1;
	while (++i < 4)
	{
		texture = &(data->tex_img[i]);
		texture->addr = mlx_get_data_addr(texture->img_ptr, \
			&(texture->bits_per_pixel), &(texture->line_length), \
			&(texture->endian));
		x = -1;
		while (++x < texture->width)
		{
			y = -1;
			while (++y < texture->height)
				data->tex[i][x][y] = get_pixel_color(texture, x, y);
		}
	}
}
