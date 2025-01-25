/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:33:52 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/25 21:41:13 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	calc_draw_limits(t_data *data, t_ray *ray)
{
	ray->wall_height = (int)(data->height / ray->perp_wall_dist * WALL);
	ray->draw_start = (int)(-ray->wall_height / 2) + (int)(data->height / 2);
	if (ray->draw_start < 0)
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

/* static void	calc_perp_dist(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
    	ray->perp_wall_dist = (ray->hit_x - player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
    	ray->perp_wall_dist = (ray->hit_y - player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
} */

static	void	choose_direction(t_ray *ray, int *map_x, int *map_y)
{
	/* if (ray->ray_index == WIDTH / 2)
	{
		printf("// choose_direction //\nRay %d\n", ray->ray_index);
		printf("Side %d\n", ray->side);
		printf("Side_dist_x: %f, side_dist_y: %f\n", ray->side_dist_x, ray->side_dist_y);
		printf("Delta_dist_x: %f, delta_dist_y: %f\n", ray->delta_dist_x, ray->delta_dist_y);
	} */
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		*map_x += ray->step_x;
		ray->side = 0;
		ray->wall_color = get_rgb(0, 0, 255);
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		*map_y += ray->step_y;
		ray->side = 1;
		ray->wall_color = get_rgb(255, 0, 0);
	}
}

void	perform_dda(t_data *data, t_ray *ray, t_player *player)
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
		{
			ray->hit = 1;
			ray->hit_x = map_x;
			ray->hit_y = map_y;
		}
	}
	calc_perp_dist(ray);
	calc_draw_limits(data, ray);
}
