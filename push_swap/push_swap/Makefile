# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/16 15:41:08 by hlin          #+#    #+#                  #
#    Updated: 2021/07/28 16:45:24 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_CHK = checker

INCLUDES = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

LIBFT_DIR = libft

SRCS = srcs/push_swap.c \
		srcs/display.c srcs/display_bonus.c \
		srcs/sort.c srcs/sort_utils.c srcs/sort_rotation.c \
		srcs/sort_move.c srcs/sort_back.c \
		srcs/args_parser.c srcs/stack.c srcs/stack_display.c \
		srcs/operation_swap.c srcs/operation_push.c \
		srcs/operation_rotation.c srcs/operation_rvrotation.c

SRCS_CHK = srcs/checker/checker.c srcs/checker/checker_utils.c \
			srcs/checker/checker_operation.c

OBJECTS = $(SRCS:.c=.o)

OBJECTS_CHK = $(SRCS_CHK:.c=.o)

CYAN = \033[38;5;81m
GREEN = \033[38;5;10m
PURPLE = \033[38;5;99m
ORANGE =  \033[38;5;172m
WHITE = \033[0m

all: $(NAME) $(NAME_CHK)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@echo "$(CYAN)libft library has been created$(WHITE)\n"

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
	@echo "$(GREEN)push_swap has been created$(WHITE)\n"

$(NAME_CHK): $(OBJECTS_CHK) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME_CHK) $(OBJECTS_CHK) $(LIBFT)
	@echo "$(GREEN)checker has been created$(WHITE)\n"

%.o: %.c $(INCLUDES)
	@$(CC) $(FLAGS) -Ilibft -c $< -o $@

clean:
	@rm -f $(OBJECTS) $(OBJECTS_CHK) $(LIBFT)
	@make clean -C $(LIBFT_DIR)
	@echo "$(PURPLE)Objects file were removed - clean.$(WHITE)\n"

fclean: clean
	@rm -f $(NAME) $(NAME_CHK)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(ORANGE)Objects file were removed - fclean.$(WHITE)\n"

re: fclean all

.PHONY: all clean fclean re
