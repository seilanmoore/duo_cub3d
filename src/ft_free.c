/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:34:54 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/28 13:53:14 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_textures_img(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (data->tex_img[i].img_ptr)
		{
			mlx_destroy_image(data->mlx, data->tex_img[i].img_ptr);
			data->tex_img[i].img_ptr = NULL;
		}
	}
}

void	free_a_tex(t_data *data)
{
	int	i;
	int	x;

	i = -1;
	while (++i < 4)
	{
		if (data->tex_img[i].width)
		{
			x = -1;
			while (++x < data->tex_img[i].width)
				free(data->tex[i][x]);
			free(data->tex[i]);
		}
		else
			break ;
	}
}

void	free_a_map(t_data *data)
{
	int	i;

	if (data->map_width)
	{
		i = -1;
		while (++i < data->map_width)
			free(data->a_map[i]);
		free(data->a_map);
	}
}

void	free_array(char ***array)
{
	int	i;

	if (*array == NULL)
		return ;
	i = -1;
	while ((*array)[++i])
	{
		free((*array)[i]);
		(*array)[i] = NULL;
	}
	free(*array);
	*array = NULL;
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}
