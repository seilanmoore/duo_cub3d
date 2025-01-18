/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:36:02 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/18 13:00:48 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_cub3d(data);
}

void	graphics(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, 1280, 720, "Cub3D");
	if (!data->mlx_win)
		clean_exit(data, "mlx_new_window", errno);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->no_tex, 50, 50);
	mlx_hook(data->mlx_win, DESTROY_NOTIF,
		NO_EVENT_MASK, (void *)close_cub3d, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, (void *)key_hook, data);
	mlx_loop(data->mlx);
}
