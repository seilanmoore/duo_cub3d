/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjezzard <jjezzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:37:46 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/15 18:10:54 by jjezzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	load_start_img(t_data *data)
{
	data->no_img = mlx_texture_to_image(data->mlx, data->no_tex);
	data->so_img = mlx_texture_to_image(data->mlx, data->so_tex);
	data->we_img = mlx_texture_to_image(data->mlx, data->we_tex);
	data->ea_img = mlx_texture_to_image(data->mlx, data->ea_tex);	
	if (!data->no_img)
		printf("north image is null\n");
	if (!data->no_tex)
		printf("north texture is null\n");
	if (!data->mlx)
		printf("mlx is null\n");
}

void	render_img(t_data *data)
{
	if (!data->mlx || !data->no_img)
	{
		printf("somethings wrong\n");
	}
	mlx_image_to_window(data->mlx, data->no_img, 10 * 2, 10 * 2);
}

int	main(int argc, char **argv)
{
	t_data	data;
	mlx_image_t* image;

	image = data.no_img;
	check_args(argc, argv);
	data = (t_data){0};
	parse_file(&data, argv[1]);
	// cleanup(&data);

	if (!(data.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	load_start_img(&data);
	printf("NULL\n");
	render_img(&data);
	

	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}




// -----------------------------------------------------------------------------

