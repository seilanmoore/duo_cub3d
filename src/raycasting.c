/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:08:23 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/25 19:31:58 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	calc_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_x)
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	else
		ray->delta_dist_x = 1e30;
	if (ray->ray_dir_y)
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	else
		ray->delta_dist_y = 1e30;
}

/* static void	calc_delta_dist(t_ray *ray)
{
	if (fabs(ray->ray_dir_x) < 1e-8)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (fabs(ray->ray_dir_y) < 1e-8)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
} */

static void	calc_ray_step(t_ray *ray, t_player player, int map_x, int map_y)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player.pos_x - map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (map_x + 1.0 - player.pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player.pos_y - map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map_y + 1.0 - player.pos_y) * ray->delta_dist_y;
	}
}

static void	calc_ray_direction(t_data *data, t_player player, int x)
{
	t_ray		*ray;

	ray = &(data->ray[x]);
	ray->camera_x = (2.0 * (double)x / (double)WIDTH) - 1.0;
	ray->ray_dir_x = player.dir_x + player.plane_x * ray->camera_x;
	ray->ray_dir_y = player.dir_y + player.plane_y * ray->camera_x;
	/* if (ray->ray_index == WIDTH / 2)
	{
		printf("Ray %d\n", ray->ray_index);
		printf("Camera_x %f\n", ray->camera_x);
		printf("Ray_dir_x: %f, ray_dir_y: %f\n", ray->ray_dir_x, ray->ray_dir_y);
	} */
	calc_delta_dist(ray);
	calc_ray_step(ray, data->player, \
		data->player.pos_x, data->player.pos_y);
}

void	start_rays(t_data *data)
{
	int	i;

	i = -1;
	while (++i < WIDTH)
	{
		data->ray[i].ray_index = i;
		calc_ray_direction(data, data->player, i);
		perform_dda(data, &(data->ray[i]), &(data->player));
	}
}
