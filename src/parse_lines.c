/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:45:40 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/15 22:00:45 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <unistd.h>

static int	count_lines(const char *file)
{
	char	*line;
	int		n_lines;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(print_msg("open", errno));
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
		exit(print_msg("close", errno));
	return (n_lines);
}

static char	**get_lines(int n_lines, int fd)
{
	char	**content;
	int		i;

	content = malloc((n_lines + 1) * sizeof(char *));
	if(!content)
	{
		close(fd);
		exit(print_msg("malloc", errno));
	}
	i = -1;
	while (++i < n_lines)
	{
		content[i] = get_next_line(fd);
		if (!(content[i]))
		{
			close(fd);
			free_array(&content);
			exit(print_msg("get_next_line", errno));
		}
	}
	content[i] = NULL;
	return (content);
}

char	**parse_lines(const char *file)
{
	char	**content;
	int		n_lines;
	int		fd;

	n_lines = count_lines(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(print_msg("open", errno));
	content = get_lines(n_lines, fd);
	if (close(fd) == -1)
		exit(print_msg("close", errno));
	return (content);
}
