/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:12:51 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/11 21:40:25 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	print_msg(const char *msg, int code)
{
	size_t	len;

	len = ft_strlen(msg);
	write(2, "Error: ", 7);
	if (!ft_strncmp(strerror(errno), "Success", 7))
	{
		write(2, msg, len);
		write(2, "\n", 1);
	}
	else
		perror(msg);
	return (code);
}
