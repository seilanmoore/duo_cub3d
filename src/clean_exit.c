/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:16:11 by smoore-a          #+#    #+#             */
/*   Updated: 2025/02/01 15:12:16 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_parse(t_parse *to_parse)
{
	free(to_parse->no_path);
	free(to_parse->so_path);
	free(to_parse->we_path);
	free(to_parse->ea_path);
	free_array(&(to_parse->content));
}

int	close_cub3d(void *data_)
{
	t_data	*data;

	data = (t_data *)data_;
	(void)data;
	clean_exit(data, NULL, 0);
	return (0);
}

static void	cleanup(t_data *data)
{
	free_textures_img(data);
	free_array(&(data->map));
	free_a_map(data);
	if (data->tex_init == true)
		free_a_tex(data);
	if (data->mlx)
	{
		if (data->frame.img_ptr)
		{
			mlx_destroy_image(data->mlx, data->frame.img_ptr);
			data->frame.img_ptr = NULL;
		}
		if (data->mlx_win)
			mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	clean_exit(t_data *data, char *msg, int code)
{
	cleanup(data);
	exit(print_msg(msg, code));
}
