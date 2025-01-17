/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjezzard <jjezzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:37:46 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/17 11:09:33 by jjezzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}



int	main(int argc, char **argv)
{
	t_data	data;
	mlx_image_t* image;

	image = data.no_img;
	check_args(argc, argv);
	data = (t_data){0};
	parse_file(&data, argv[1]);
	graphics(&data);
	clean_exit(&data, NULL, 0);
	cleanup(&data);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
