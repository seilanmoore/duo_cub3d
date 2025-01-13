/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:34:54 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/12 20:30:01 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_parse(t_parse *to_parse)
{
	free(to_parse->no_path);
	free(to_parse->so_path);
	free(to_parse->we_path);
	free(to_parse->ea_path);
	free_array(&(to_parse->content));
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
