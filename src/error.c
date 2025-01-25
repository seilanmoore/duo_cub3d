/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:12:51 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/18 13:54:43 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <string.h>

int	print_msg(const char *msg, int code)
{
	size_t	len;

	if (!msg)
		return (code);
	len = ft_strlen(msg);
	write(2, "Error: ", 7);
	if (!ft_strncmp(strerror(errno), "Success", 7) || \
	!ft_strncmp(strerror(errno), "Resource temporarily unavailable", 32))
	{
		write(2, msg, len);
		write(2, "\n", 1);
	}
	else
		perror(msg);
	return (code);
}
