# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smoore-a <smoore-a@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 16:39:43 by smoore-a          #+#    #+#              #
#    Updated: 2025/02/01 11:19:50 by smoore-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCLUDE = -Iinclude -Ilib/libft/include -I/usr/include -Ilib/minilibx-linux

HEADER = cub3d.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address -fno-omit-frame-pointer
#ASAN_OPTIONS=detect_leaks=1

L_FLAGS = -Llib/libft -lft \
	-Llib/minilibx-linux -lmlx_Linux \
	-L/usr/lib -lXext -lX11 -lm -lbsd

LIBFT = lib/libft/libft.a

MLX = lib/minilibx-linux/libmlx_Linux.a

RM = rm -rf

SRC_DIR = src/

OBJ_DIR = obj/

SRC = main check_args check_map check_map_utils \
	parse_file parse_lines parse_colors parse_map parse_textures parse_utils \
	init_data init_utils_player init_utils_map  init_utils_tex \
	graphics raycasting dda draw draw_utils \
	player_move player_rotation limit_fps \
	ft_free clean_exit error

OBJ_FILES = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

VPATH = src:include

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(L_FLAGS) -o $@
	@echo "$(NAME) compiled"

$(OBJ_DIR)%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$< compiled"

$(LIBFT):
	@make all -C lib/libft
	@echo "Libft compiled"

$(MLX):
	@make all -C lib/minilibx-linux
	@echo "Minilibx compiled"

mlxclean:
	@make clean -C lib/minilibx-linux
	@echo "Minilibx removed"

clean:
	$(RM) $(OBJ_DIR)
	@echo "Object files removed"
	@make clean -C lib/libft
	@echo "Libft object files removed"

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) removed"
	$(RM) $(LIBFT)
	@echo "$(LIBFT) removed"

re: fclean all

nocflag:
	$(MAKE) $(LIBFT)
	$(MAKE) CFLAGS="" $(NAME)

.PHONY: all clean mlxclean fclean re nocflag

ifndef VERBOSE
.SILENT:
endif
