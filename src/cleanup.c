/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:16:11 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/18 13:06:20 by smoore-a         ###   ########.fr       */
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

void	cleanup(t_data *data)
{
	if (data->no_tex)
		mlx_destroy_image(data->mlx, data->no_tex);
	if (data->so_tex)
		mlx_destroy_image(data->mlx, data->so_tex);
	if (data->we_tex)
		mlx_destroy_image(data->mlx, data->we_tex);
	if (data->ea_tex)
		mlx_destroy_image(data->mlx, data->ea_tex);
	free_array(&(data->map));

}

int	clean_exit(t_data *data, char *msg, int code)
{
	cleanup(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(print_msg(msg, code));
}

void	close_cub3d(void *data_)
{
	t_data	*data;

	data = (t_data *)data_;
	clean_exit(data, NULL, 0);
}
