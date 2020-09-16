# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: anonymous <anonymous@student.codam.nl>       +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/27 21:28:48 by anonymous     #+#    #+#                  #
#    Updated: 2020/08/27 21:28:48 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

Name = cub3D

SRCFILE = bmp.c check.c colour.c config.c cub3d.c exit.c init.c input.c \
map.c parser.c raycaster.c render.c sort.c sprite.c \
ui.c utils.c utils2.c

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

SRC = $(addprefix src/, $(SRCFILE))

OBJ = $(SRC:.c=.o) $(GNL:.c=.o)

HEADER = includes/cub3d.h includes/cub3d_stryct.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3

# for MAc
MLXDIR = minilibx
DYLIB = libmlx.dylib
LIB = -framework OpenGL -framework Appkit
MLX = -L$(MLXDIR) -lmlx

# for Linux
# MLXDIR = mlx_linux
# DYLIB = libmlx.a
# LIB = -Lmlx_linux -lmlx -lXext -lX11 -lm -lz -AppKit
# MLX = -L$(MLXDIR) -lmlx

# colors
BLUE = \033[38;5;27m
CYAN = \033[38;5;51m
PINK = \033[38;5;211m
GREEN = \033[38;5;72m
TURQ = \033[38;5;37m
WHITE = \033[38;5;15m
YELLOW = \033[38;5;220m
C = \033[38;5;
O = 72
L = m
SHIFT = $(eval O=$(shell echo $$((($(O)%15)+1))))

LBOR = "▌│█║▌║▌║ "
RBOR = " ║▌║▌║█│▌"

all: $(NAME)

.PHONY: all clean fclean re

$(NAME): $(OBJ) $(MLX)
	@$(MAKE) subzero
	@$(CC) $(FLAGS) $(OBJ) $(MLX) $(LIB) -o $(NAME)
	@echo "\n\t   $(TURQ)$(LBOR)Game compiled$(RBOR)$(WHITE)\n"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

$(MLX):
	@make -C $(MLXDIR)
	@cp -rf $(MLXDIR)/$(DYLIB) .
	@echo "\n\t   $(TURQ)$(LBOR)minilibx compiled$(RBOR)$(WHITE)\n"

clean:
	@echo "\n\t   $(PINK)$(LBOR)Cleaning$(RBOR)$(WHITE)\n"
	@rm -rf $(OBJ)
	@make -C $(MLXDIR) clean

fclean: clean
	@echo "\n\t   $(CYAN)$(LBOR)Clean af$(RBOR)$(WHITE)\n"
	@rm -rf $(NAME)
	@rm -rf libmlx.dylib
	@rm -rf screenshot.bmp

re:
	@echo "\n\t   $(BLUE)$(LBOR)Aww here we go again$(RBOR)$(WHITE)\n"
	@$(MAKE) fclean
	@$(MAKE) all

subzero:
	@echo "$(C)$(O)$(L) ______     __  __     ______     ______     _____    ";
	@echo "$(C)$(O)$(L)/\  ___\   /\ \/\ \   /\  == \   /\___  \   /\  __ \  ";
	$(SHIFT)
	@echo "$(C)$(O)$(L)\ \ \____  \ \ \_\ \  \ \  __<   \/_\___ \  \ \ \_\ \ ";
	@echo "$(C)$(O)$(L) \ \_____\  \ \_____\  \ \_____\  /\______\  \ \____/ ";
	$(SHIFT)
	@echo "$(C)$(O)$(L)  \/_____/   \/_____/   \/_____/  \/______/   \/____/ ";
	@echo "$(C)$(O)$(L)                                                      ";