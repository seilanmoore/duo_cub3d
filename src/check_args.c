/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:04:41 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/13 09:13:43 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	valid_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	while (len-- > 4)
		filename++;
	if (ft_strncmp(filename, ".cub", 4))
		return (false);
	return (true);
}

static bool	valid_filename(char *filename)
{
	if (!valid_extension(filename))
		return (false);
	return (true);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		exit(print_msg(PROTOTYPE, 1));
	if (!valid_filename(argv[1]))
		exit(print_msg(PROTOTYPE, 1));
}
