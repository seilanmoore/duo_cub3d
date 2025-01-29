/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:33:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/29 17:41:48 by smoore-a         ###   ########.fr       */
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
		my_mlx_pixel_put(&(data->frame), x, \
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
		my_mlx_pixel_put(&(data->frame), x, \
		y++, get_rgb(floor[0], floor[1], floor[2]));
	}
}

static void	draw_ray(t_data *data, int x)
{
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		y;

	tex_x = get_tex_x(data, x);
	step = (double)data->tex_img[data->ray[x].wall_dir].height / \
		data->ray[x].wall_height;
	tex_pos = (data->ray[x].draw_start - (double)HEIGHT / 2 + \
		(double)data->ray[x].wall_height / 2) * step;
	draw_ceiling(data, x);
	y = data->ray[x].draw_start;
	while (y <= data->ray[x].draw_end)
	{
		tex_y = (int)tex_pos & \
			(data->tex_img[data->ray[x].wall_dir].height - 1);
		tex_pos += step;
		my_mlx_pixel_put(&(data->frame), x, \
		y++, data->tex[data->ray[x].wall_dir][tex_x][tex_y]);
	}
	draw_floor(data, x, y);
}

int	draw_frame(t_data *data)
{
	int	i;

	handle_movement(data);
	data->frame.img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->frame.img_ptr)
		clean_exit(data, "mlx_new_image", 1);
	data->frame.addr = \
		mlx_get_data_addr(\
		data->frame.img_ptr, &data->frame.bits_per_pixel, \
		&data->frame.line_length, &data->frame.endian);
	raycasting(data);
	i = -1;
	while (++i < WIDTH)
		draw_ray(data, i);
	mlx_put_image_to_window(\
		data->mlx, data->mlx_win, data->frame.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx, data->frame.img_ptr);
	data->frame.img_ptr = NULL;
	limit_fps(data);
	return (0);
}
