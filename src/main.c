/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:37:46 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/18 13:07:26 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	data = (t_data){0};
	data.mlx = mlx_init();
	if (!data.mlx)
		exit(print_msg("mlx_init", 1));
	parse_file(&data, argv[1]);
	graphics(&data);
	cleanup(&data);
	clean_exit(&data, NULL, 0);
	return (EXIT_SUCCESS);
}
