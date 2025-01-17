/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:52:47 by smoore-a          #+#    #+#             */
/*   Updated: 2025/01/18 12:16:42 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/include/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include <stdbool.h>

# define PROTOTYPE "prototype: ./cub3d MAP_FILENAME_PATH"

# define DESTROY_NOTIF 17
# define NO_EVENT_MASK 0

# define WIDTH 500
# define HEIGHT 500

typedef struct s_parse
{
	int		row_b4_map;
	char	**content;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_color[3];
	int		ceiling_color[3];
	char	**map;
}	t_parse;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*no_tex;
	void	*so_tex;
	void	*we_tex;
	void	*ea_tex;
	int		floor_color[3];
	int		ceiling_color[3];
	char	**map;
}	t_data;


// check_args //
void	check_args(int argc, char **argv);

// check_map //
void	check_map(t_data *data);

// parse_file //
void	parse_file(t_data *data, const char *file);

// parse_lines //
char	**parse_lines(t_data *data, const char *file);

// parse_elements //
void	parse_elements(t_data *data, t_parse *to_parse);

// parse_textures //
void	parse_textures(t_data *data, t_parse *to_parse);

// parse_colors //
void	parse_colors(t_data *data, t_parse *to_parse);

// parse_map //
void	parse_map(t_data *data, t_parse *to_parse);

// parse_utils //
void	check_several_coord(t_data *data, char **map);
char	*seek_element(char **content, char *element, int *row_b4_map);
char	**seek_map(char **content);

// graphics //
void	graphics(t_data *data);

// error //
int		print_msg(const char *msg, int code);

// ft_free //
void	free_array(char ***array);
void	ft_free(char **str);
void	free_parse(t_parse *to_parse);

// cleanup //
void	close_cub3d(void *data_);
void	cleanup(t_data *data);
int		clean_exit(t_data *data, char *msg, int code);

#endif
