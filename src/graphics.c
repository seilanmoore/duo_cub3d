/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjezzard <jjezzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:36:02 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/17 12:19:21 by jjezzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
} */

int	print_img(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P')
		// if (mlx_image_to_window(data->mlx, data->img_char, j * 128, i * 75) == -1)
		// 	error_return(*data, 1);
	if (data->map[i][j] == 'P'
		|| data->map[i][j] == 'C'
		|| data->map[i][j] == '0')
		// if (mlx_image_to_window(data->mlx, data->img_back, j * 128, i * 75) == -1)
		// 	error_return(*data, 1);
	if (data->map[i][j] == '1')
		// if (mlx_image_to_window(data->mlx, data->img_wall, j * 128, i * 75) == -1)
		// 	error_return(*data, 1);
	if (data->map[i][j] == 'C')
		// if (mlx_image_to_window(data->mlx, data->img_coll, j * 128, i * 75) == -1)
		// 	error_return(*data, 1);
	if (data->map[i][j] == 'E')
		// if (mlx_image_to_window(data->mlx, data->img_exit, j * 128, i * 75) == -1)
		// 	error_return(*data, 1);
	return (1);
	return (1);
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
	mlx_image_to_window(data->mlx, data->no_img, 0, 0);
}
void	key_press(mlx_key_data_t entry, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (entry.key == MLX_KEY_W && entry.action == MLX_REPEAT)
		printf("w\n");
	if (entry.key == MLX_KEY_A && entry.action == MLX_REPEAT)
		printf("a\n");
	if (entry.key == MLX_KEY_S && entry.action == MLX_REPEAT)
		printf("s\n");
	if (entry.key == MLX_KEY_D && entry.action == MLX_REPEAT)
		printf("d\n");
	if (entry.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
}

void	graphics(t_data *data)
{
	if (!(data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		cleanup(data);
		exit(print_msg("mlx_init", errno));
	}
	load_start_img(data);
	render_img(data);
	mlx_key_hook(data->mlx, key_press, data);
	mlx_close_hook(data->mlx, close_cub3d, data);
	// mlx_loop_hook(data->mlx, ft_hook, data->mlx);
	mlx_loop(data->mlx);
	/* mlx_loop_hook(data->mlx, ft_hook, mlx);
	mlx_loop(data->mlx); */
}
