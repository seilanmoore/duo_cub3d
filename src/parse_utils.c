/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:59:07 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/28 11:28:29 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*seek_element(char **content, char *element, int *row_b4_map)
{
	char	*str;
	int		i;

	i = -1;
	while (content[++i])
	{
		str = ft_strtrim(content[i], " \t\n\r\v\f");
		if (!ft_strncmp(str, element, ft_strlen(element)))
		{
			free(str);
			if (*row_b4_map < i)
				*row_b4_map = i;
			return (content[i]);
		}
		free(str);
	}
	return (NULL);
}

char	**seek_map(char **content)
{
	int	i;

	i = -1;
	while (content[++i])
	{
		if (ft_strchr(content[i], '1') || \
		ft_strchr(content[i], '0') || \
		ft_strchr(content[i], 'N') || \
		ft_strchr(content[i], 'S') || \
		ft_strchr(content[i], 'W') || \
		ft_strchr(content[i], 'E'))
			return (&(content[i]));
	}
	return (NULL);
}
