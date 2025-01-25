/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:34:54 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/24 13:48:11 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_a_map(t_data *data)
{
	int	i;

	if (data->map_width && data->map_width)
	{
		i = -1;
		while (++i < data->map_width)
			free(data->a_map[i]);
	}
	if (data->map_width)
		free(data->a_map);
}

void	free_array(char ***array)
{
	int	i;

	if (*array == NULL)
		return ;
	i = -1;
	while ((*array)[++i])
	{
		free((*array)[i]);
		(*array)[i] = NULL;
	}
	free(*array);
	*array = NULL;
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}
