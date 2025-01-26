/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:33:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/26 14:39:37 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	handle_movement(t_data *data)
{
	if (data->key.w)
		move_forward(data);
	if (data->key.s)
		move_backwards(data);
	if (data->key.a)
		move_to_left(data);
	if (data->key.d)
		move_to_right(data);
	if (data->key.left)
		rotate_player_left(data);
	if (data->key.right)
		rotate_player_right(data);
}

static void	draw_ceiling(t_data *data, int x)
{
	int	ceiling[3];
	int	y;

	ceiling[0] = data->ceiling_color[0];
	ceiling[1] = data->ceiling_color[1];
	ceiling[2] = data->ceiling_color[2];
	y = 0;
	while (y < data->ray[x].draw_start)
	{
		my_mlx_pixel_put(data, x, \
		y++, get_rgb(ceiling[0], ceiling[1], ceiling[2]));
	}
}

static void	draw_floor(t_data *data, int x, int y)
{
	int	floor[3];

	floor[0] = data->floor_color[0];
	floor[1] = data->floor_color[1];
	floor[2] = data->floor_color[2];
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(data, x, \
		y++, get_rgb(floor[0], floor[1], floor[2]));
	}
}

static void	draw_ray(t_data *data, int x)
{
	int	y;

	/* if (x == WIDTH / 2)
	{
		printf("ray %d\n", x);
		printf("Ray central: dir_x = %f, dir_y = %f\n", data->ray[x].ray_dir_x, data->ray[x].ray_dir_y);
		printf("Delta dist: x = %f, y = %f\n", data->ray[x].delta_dist_x, data->ray[x].delta_dist_y);
		printf("Map coords: x = %d, y = %d\n", data->ray[x].hit_x, data->ray[x].hit_y);
		printf("Hit: %d\n", data->ray[x].hit);
		printf("Wall height: %d\n", data->ray[x].wall_height);
		printf("Draw start: %d, Draw end: %d\n", data->ray[x].draw_start, data->ray[x].draw_end);
		printf("Side dist x: %f, Side dist y: %f\n", data->ray[x].side_dist_x, data->ray[x].side_dist_y);
		printf("Perp wall dist: %f\n", data->ray[x].perp_wall_dist);
	} */
	draw_ceiling(data, x);
	y = data->ray[x].draw_start;
	while (y <= data->ray[x].draw_end)
	{
		my_mlx_pixel_put(data, x, \
		y++, data->ray[x].wall_color);
	}
	draw_floor(data, x, y);
}

int	draw_frame(t_data *data)
{
	int	i;

	handle_movement(data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		clean_exit(data, "mlx_new_image", 1);
	data->addr = \
		mlx_get_data_addr(\
		data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	start_rays(data);
	i = -1;
	while (++i < WIDTH)
		draw_ray(data, i);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	data->img = NULL;
	limit_fps(data);
	return (0);
}
