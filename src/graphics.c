/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:36:02 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/29 15:43:07 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->key.w = 1;
	else if (keycode == XK_s)
		data->key.s = 1;
	else if (keycode == XK_a)
		data->key.a = 1;
	else if (keycode == XK_d)
		data->key.d = 1;
	else if (keycode == XK_Left)
		data->key.left = 1;
	else if (keycode == XK_Right)
		data->key.right = 1;
	else if (keycode == XK_Escape)
		close_cub3d(data);
	return (0);
}

static int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->key.w = 0;
	else if (keycode == XK_s)
		data->key.s = 0;
	else if (keycode == XK_a)
		data->key.a = 0;
	else if (keycode == XK_d)
		data->key.d = 0;
	else if (keycode == XK_Left)
		data->key.left = 0;
	else if (keycode == XK_Right)
		data->key.right = 0;
	else if (keycode == XK_Escape)
		close_cub3d(data);
	return (0);
}

void	graphics(t_data *data)
{
	init_data(data);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->mlx_win)
		clean_exit(data, "mlx_new_window", 1);
	mlx_loop_hook(data->mlx, draw_frame, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(data->mlx_win, DESTROY_NOTIF,
		NO_EVENT_MASK, close_cub3d, data);
	mlx_loop(data->mlx);
}
