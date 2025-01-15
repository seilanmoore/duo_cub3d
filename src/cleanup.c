/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:16:11 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/15 22:40:07 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <string.h>

void	cleanup(t_data *data)
{
	mlx_delete_texture(data->no_tex);
	mlx_delete_texture(data->so_tex);
	mlx_delete_texture(data->we_tex);
	mlx_delete_texture(data->ea_tex);
	free_array(&(data->map));
}

int	clean_exit(t_data *data, char *msg, int code)
{
	cleanup(data);
	mlx_terminate(data->mlx);
	exit(print_msg(msg, code));
}

void	close_cub3d(void *data_)
{
	t_data *data;

	data = (t_data *)data_;
	clean_exit(data, NULL, 0);
}
