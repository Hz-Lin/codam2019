# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2020/09/23 15:10:50 by hlin          #+#    #+#                  #
#    Updated: 2020/10/04 16:39:21 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEADER = cub3d.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX = mlx

LIBMLX = libmlx.dylib

BMP = screenshot.bmp

SRCFILE = action.c cub3d.c drawer.c exit.c init_game.c init_struct.c \
		movements.c parse_floor_ceiling.c parse_map_check.c parse_map_sprite.c \
		parse_map.c parse_mapfile.c parse_res.c parse_tex.c raycasting.c \
		render_map.c render_sprites_sort.c render_sprites.c screensave.c \
		utils_one.c utils_two.c

SRC = $(addprefix src/, $(SRCFILE))

GNL	=gnl/get_next_line.c gnl/get_next_line_utils.c

OBJECTS = $(SRC:.c=.o) $(GNL:.c=.o)

all: $(NAME)

$(LIBMLX):
	@make -C $(MLX)
	@cp $(MLX)/$(LIBMLX) .
	@echo "mlx library has been created"

$(NAME): $(OBJECTS) $(LIBMLX)
	@$(CC) $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJECTS)
	@echo "cub3D has been created"

%.o: %.c $(HEADERS)
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

bonus: $(ALL)

clean:
	@rm -f $(OBJECTS) $(LIBMLX) $(BMP)
	@make clean -C $(MLX)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
