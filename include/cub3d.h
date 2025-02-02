/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:52:47 by smoore-a          #+#    #+#             */
/*   Updated: 2025/02/02 23:44:02 by smoore-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/include/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <bits/types/struct_timeval.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

# define PROTOTYPE "prototype: ./cub3d MAP_FILENAME_PATH"

# define DESTROY_NOTIF 17
# define NO_EVENT_MASK 0

# define WIDTH 1920 // 640
# define HEIGHT 1080 // 480

# define WALL 1
# define FOV 66
# define ROT_SPEED 1
# define MOVE_SPEED 1
# define FPS_LIMIT 60

typedef struct timeval	t_timeval;

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_dir;

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_key;

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

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x; // Dirección X del rayo
	double	ray_dir_y; // Dirección Y del rayo
	double	delta_dist_x; // Distancia entre pasos en X
	double	delta_dist_y; // Distancia entre pasos en Y
	double	side_dist_x; // Distancia inicial al siguiente lado en X
	double	side_dist_y; // Distancia inicial al siguiente lado en Y
	double	perp_wall_dist;
	int		step_x; // Dirección de los pasos en X (-1 o 1)
	int		step_y; // Dirección de los pasos en Y (-1 o 1)
	int		hit; // Indica si el rayo golpeó una pared (0 o 1)
	int		side; // Lado de la pared golpeada (0 = X, 1 = Y)
	int		wall_height;
	int		draw_start;
	int		draw_end;
	int		wall_color;
	t_dir	wall_dir;
}	t_ray;

typedef struct s_player
{
	double	pos_x; // Posición X del jugador en el mapa
	double	pos_y; // Posición Y del jugador en el mapa
	double	dir_x; // Dirección X en la que está mirando
	double	dir_y; // Dirección Y en la que está mirando
	double	plane_x; // Componente X del plano de la cámara (para el FOV)
	double	plane_y; // Componente Y del plano de la cámara (para el FOV)
	double	move_speed; // Velocidad de movimiento
	double	rot_speed; // Velocidad de rotación
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	char		init_dir;
	int			floor_color[3];
	int			ceiling_color[3];
	char		**map;
	int			**a_map;
	int			map_width;
	int			map_height;
	double		width;
	double		height;
	t_img		frame;
	t_img		tex_img[4];
	bool		tex_init;
	int			**tex[4];
	time_t		time;
	time_t		old_time;
	t_key		key;
	t_player	player;
	t_ray		ray[WIDTH];
}	t_data;

// check_args //
void	check_args(int argc, char **argv);

// check_map //
void	check_map(t_data *data);

// check_map_utils //
void	check_several_dir(t_data *data, char **map);

// parse_file //
void	parse_file(t_data *data, const char *file);

// parse_lines //
char	**parse_lines(t_data *data, const char *file);

// parse_textures //
void	parse_textures(t_data *data, t_parse *to_parse);

// parse_textures_utils //
void	image_to_array(t_data *data);

// parse_colors //
void	parse_colors(t_data *data, t_parse *to_parse);

// parse_map //
void	parse_map(t_data *data, t_parse *to_parse);

// parse_utils //
char	*seek_element(char **content, char *element, int *row_b4_map);
char	**seek_map(char **content);

// init_data //
void	init_data(t_data *data);

// init_utils_player //
void	set_player_position(t_data *data, t_player *player);
void	set_player_direction(t_player *player, int init_dir);
void	set_plane(t_player *player);

// init_utils_map //
void	convert_map(t_data *data);

// player_move //
void	move_forward(t_data *data);
void	move_backwards(t_data *data);
void	move_to_left(t_data *data);
void	move_to_right(t_data *data);
void	handle_movement(t_data *data);

// player_rotation //
void	rotate_player_left(t_data *data);
void	rotate_player_right(t_data *data);

// graphics //
void	graphics(t_data *data);

// ray //
void	raycasting(t_data *data);

// dda //
void	dda(t_data *data, t_ray *ray, t_player *player);

// draw //
int		draw_frame(t_data *data);

// draw_utils //
int		get_tex_x(t_data *data, int x);
int		get_rgb(int r, int g, int b);
int		get_pixel_color(t_img *img, int x, int y);
int		my_mlx_pixel_put(t_img *frame, int x, int y, int color);

// limit_fps //
void	limit_fps(t_data *data);

// error //
int		print_msg(const char *msg, int code);

// ft_free //
void	free_textures_img(t_data *data);
void	free_a_tex(t_data *data);
void	free_a_map(t_data *data);
void	free_array(char ***array);
void	ft_free(char **str);

// cleanup //
void	free_parse(t_parse *to_parse);
int		close_cub3d(void *data_);
int		clean_exit(t_data *data, char *msg, int code);

#endif
