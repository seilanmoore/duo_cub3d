/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:36:02 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/26 00:11:36 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_cub3d(data);
	else if (keycode == XK_Left)
		rotate_player_left(data);
	else if (keycode == XK_Right)
		rotate_player_right(data);
}

void	graphics(t_data *data)
{
	init_data(data);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->mlx_win)
		clean_exit(data, "mlx_new_window", 1);
	mlx_loop_hook(data->mlx, (void *)draw_frame, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, (void *)key_hook, data);
	mlx_hook(data->mlx_win, DESTROY_NOTIF,
		NO_EVENT_MASK, (void *)close_cub3d, data);
	mlx_loop(data->mlx);
}
