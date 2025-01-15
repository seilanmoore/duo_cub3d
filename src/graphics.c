/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:36:02 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/15 22:27:04 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
} */

void	graphics(t_data *data)
{
	data->mlx = mlx_init(900, 600, "Cub3D", true);
	if (!data->mlx)
	{
		cleanup(data);
		exit(print_msg("mlx_init", errno));
	}
	mlx_close_hook(data->mlx, close_cub3d, data);
	//mlx_loop_hook(data->mlx, ft_hook, data->mlx);
	mlx_loop(data->mlx);
	/* mlx_loop_hook(data->mlx, ft_hook, mlx);
	mlx_loop(data->mlx); */
}
