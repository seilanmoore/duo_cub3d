/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:33:52 by smoore-a          #+#    #+#             */
/*   Updated: 2025/02/01 10:50:31 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	calc_draw_limits(t_data *data, t_ray *ray)
{
	ray->wall_height = (int)(data->height / ray->perp_wall_dist * WALL);
	if (ray->wall_height < 0)
		ray->wall_height = data->height;
	ray->draw_start = (int)(-ray->wall_height / 2) + (int)(data->height / 2);
	if (ray->draw_start < 0 || ray->draw_start > HEIGHT)
		ray->draw_start = 0;
	ray->draw_end = (int)(ray->wall_height / 2) + (int)(data->height / 2);
	if (ray->draw_end >= data->height)
		ray->draw_end = data->height - 1;
}

static void	calc_perp_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

static	void	choose_direction(t_ray *ray, int *map_x, int *map_y)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		*map_x += ray->step_x;
		ray->side = 0;
		if (ray->ray_dir_x > 0)
			ray->wall_dir = EAST;
		else
			ray->wall_dir = WEST;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		*map_y += ray->step_y;
		ray->side = 1;
		if (ray->ray_dir_y > 0)
			ray->wall_dir = SOUTH;
		else
			ray->wall_dir = NORTH;
	}
}

void	dda(t_data *data, t_ray *ray, t_player *player)
{
	int	map_x;
	int	map_y;

	map_x = (int)player->pos_x;
	map_y = (int)player->pos_y;
	ray->hit = 0;
	while (ray->hit == 0)
	{
		choose_direction(ray, &map_x, &map_y);
		if (data->a_map[map_x][map_y] == 1)
			ray->hit = 1;
	}
	calc_perp_dist(ray);
	calc_draw_limits(data, ray);
}
