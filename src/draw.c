/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:33:45 by smoore-a          #+#    #+#             */
/*   Updated: 2025/02/05 15:23:41 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	draw_ceiling(t_data *data, int x)
{
	int	ceiling[3];
	int	y;

	ceiling[0] = data->ceiling_color[0];
	ceiling[1] = data->ceiling_color[1];
	ceiling[2] = data->ceiling_color[2];
	y = 0;
	while (y < data->ray[x].draw_start)
	{
		if (my_mlx_pixel_put(&(data->frame), x, \
		y++, get_rgb(ceiling[0], ceiling[1], ceiling[2])) == 1)
			return (1);
	}
	return (0);
}

static	int	draw_wall(t_data *data, int x)
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
	y = data->ray[x].draw_start;
	while (y <= data->ray[x].draw_end)
	{
		tex_y = (int)tex_pos & \
			(data->tex_img[data->ray[x].wall_dir].height - 1);
		tex_pos += step;
		if (my_mlx_pixel_put(&(data->frame), x, \
		y++, data->tex[data->ray[x].wall_dir][tex_x][tex_y]) == 1)
			return (1);
	}
	return (0);
}

static int	draw_floor(t_data *data, int x)
{
	int	floor[3];
	int	y;

	floor[0] = data->floor_color[0];
	floor[1] = data->floor_color[1];
	floor[2] = data->floor_color[2];
	y = data->ray[x].draw_end + 1;
	while (y < HEIGHT)
	{
		if (my_mlx_pixel_put(&(data->frame), x, \
		y++, get_rgb(floor[0], floor[1], floor[2])) == 1)
			return (1);
	}
	return (0);
}

static int	draw_ray(t_data *data, int x)
{
	if (draw_ceiling(data, x) == 1)
		return (1);
	if (draw_wall(data, x) == 1)
		return (1);
	if (draw_floor(data, x) == 1)
		return (1);
	return (0);
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
	{
		if (draw_ray(data, i) == 1)
			clean_exit(data, "my_mlx_pixel_put", 1);
	}
	mlx_put_image_to_window(\
		data->mlx, data->mlx_win, data->frame.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx, data->frame.img_ptr);
	data->frame.img_ptr = NULL;
	limit_fps(data);
	return (0);
}
