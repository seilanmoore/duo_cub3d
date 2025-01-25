/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:45:40 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/18 13:58:52 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <unistd.h>

static int	count_lines(t_data *data, const char *file)
{
	char	*line;
	int		n_lines;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		clean_exit(data, "open", errno);
	n_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		n_lines++;
	}
	if (close(fd) == -1)
		clean_exit(data, "close", errno);
	return (n_lines);
}

static char	**get_lines(t_data *data, int n_lines, int fd)
{
	char	**content;
	int		i;

	content = malloc((n_lines + 1) * sizeof(char *));
	if (!content)
	{
		close(fd);
		clean_exit(data, "malloc", errno);
	}
	i = -1;
	while (++i < n_lines)
	{
		content[i] = get_next_line(fd);
		if (!(content[i]))
		{
			close(fd);
			free_array(&content);
			clean_exit(data, "get_next_line", 1);
		}
	}
	content[i] = NULL;
	return (content);
}

char	**parse_lines(t_data *data, const char *file)
{
	char	**content;
	int		n_lines;
	int		fd;

	n_lines = count_lines(data, file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		clean_exit(data, "open", errno);
	content = get_lines(data, n_lines, fd);
	if (close(fd) == -1)
		clean_exit(data, "close", errno);
	return (content);
}
