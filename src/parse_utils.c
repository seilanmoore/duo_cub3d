/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:59:07 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/13 18:35:15 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static	void	increase_coord(int c, int *coord)
{
	if (c == 'N')
		coord[0]++;
	else if (c == 'S')
		coord[1]++;
	else if (c == 'W')
		coord[2]++;
	else if (c == 'E')
		coord[3]++;
}

void	check_several_coord(t_data *data, char **map)
{
	int	coord[4];
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
		coord[i] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			increase_coord(map[i][j], coord);
	}
	if ((coord[0] + coord[1] + coord[2] + coord[3]) != 1)
	{
		cleanup(data);
		exit(print_msg("bad map: bad coordinate", errno));
	}
}

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
