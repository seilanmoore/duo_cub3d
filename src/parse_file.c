/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:03:51 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/18 12:18:57 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_file(t_data *data, const char *file)
{
	t_parse	to_parse;

	to_parse = (t_parse){0};
	to_parse.content = parse_lines(data, file);
	parse_textures(data, &to_parse);
	parse_colors(data, &to_parse);
	parse_map(data, &to_parse);
	// printf("Valid map:\n");
	// int	i = -1;
	// while (data->map[++i])
	// 	printf("%s\n", data->map[i]);
}
