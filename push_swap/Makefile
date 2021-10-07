# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/16 15:41:08 by hlin          #+#    #+#                  #
#    Updated: 2021/09/29 17:42:00 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_CHK = checker

INCLUDES = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

LIBFT_DIR = libft

SRCS = srcs/push_swap/data_median.c \
		srcs/push_swap/data_min_max.c \
		srcs/push_swap/display.c \
		srcs/push_swap/display_parser.c \
		srcs/push_swap/operations.c \
		srcs/push_swap/procced_op_replace.c \
		srcs/push_swap/proceed_op_delete.c \
		srcs/push_swap/ps_utils.c \
		srcs/push_swap/push_swap.c \
		srcs/push_swap/quick_sort.c \
		srcs/push_swap/quick_sort_splita.c \
		srcs/push_swap/quick_sort_splitb.c \
		srcs/push_swap/simple_sort.c\
		srcs/push_swap/ps_sorting.c

SRCS_CHK = srcs/push_swap/ps_utils.c \
		srcs/checker/checker.c \
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
