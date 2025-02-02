/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:52:56 by smoore-a          #+#    #+#             */
/*   Updated: 2025/02/02 23:36:40 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_tex_x(t_data *data, int x)
{
	double	wall_x;
	int		tex_x;

	if (data->ray[x].side == 0)
	{
		wall_x = data->player.pos_y + \
		data->ray[x].perp_wall_dist * data->ray[x].ray_dir_y;
	}
	else
	{
		wall_x = data->player.pos_x + \
		data->ray[x].perp_wall_dist * data->ray[x].ray_dir_x;
	}
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)data->tex_img[data->ray[x].wall_dir].width);
	if (data->ray[x].side == 0 && data->ray[x].ray_dir_x > 0)
		tex_x = data->tex_img[data->ray[x].wall_dir].width - tex_x - 1;
	if (data->ray[x].side == 1 && data->ray[x].ray_dir_y < 0)
		tex_x = data->tex_img[data->ray[x].wall_dir].width - tex_x - 1;
	return (tex_x);
}

int	get_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

int	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return (1);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}
