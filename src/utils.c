/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:33:42 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/24 11:29:38 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	get_coord_rad(int coord)
{
	double	rad;

	if (coord == 'N')
		rad = M_PI / 2;
	else if (coord == 'S')
		rad = (3 * M_PI) / 2;
	else if (coord == 'W')
		rad = M_PI;
	else
		rad = 0;
	return (rad);
}
