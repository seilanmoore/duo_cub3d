# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 16:39:43 by smoore-a          #+#    #+#              #
#    Updated: 2025/01/10 17:23:02 by smoore-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

INCLUDE = -Iinclude -Ilibft/include -I/usr/include -IMLX42/include

HEADER = cub3d.h

CC = clang

CFLAGS = -g -Wall -Werror -Wextra -O0 # -O0 -fsanitize=address

L_FLAGS = -Llibft -lft -LMLX42/build -lmlx42

LIBFT = libft/libft.a

RM = rm -rf

SRC_DIR = src/

OBJ_DIR = obj/

SRC = main 

OBJ_FILES = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

VPATH = src:include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(L_FLAGS) -o $@
	@echo "$(NAME) compiled"

$(OBJ_DIR)%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$< compiled"

$(LIBFT):
	@make all -C libft
	@echo "$(LIBFT) compiled"

#bonus:
#	@make all -C bonus

clean:
	$(RM) $(OBJ_DIR)
	@echo "Object files removed"
	@make clean -C libft
	@echo "Libft object files removed"
#	@make clean -C bonus
#	@echo "Bonus object files removed"

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) removed"
	$(RM) $(LIBFT)
	@echo "$(LIBFT) removed"
#	$(RM) $(BONUS)
#	@echo "$(BONUS) removed"

re: fclean all

nocflag:
	$(MAKE) $(LIBFT)
	$(MAKE) CFLAGS="" $(NAME)

.PHONY: all clean fclean re bonus nocflag

ifndef VERBOSE
.SILENT:
endif