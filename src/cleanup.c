/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:16:11 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/12 18:23:00 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cleanup(t_data *data)
{
	mlx_delete_texture(data->no_tex);
	mlx_delete_texture(data->so_tex);
	mlx_delete_texture(data->we_tex);
	mlx_delete_texture(data->ea_tex);
	free_array(&(data->map));
}
