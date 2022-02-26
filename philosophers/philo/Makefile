# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/23 14:36:14 by hlin          #+#    #+#                  #
#    Updated: 2022/02/23 10:28:59 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LDFLAGS	=	-lpthread

INCS	=	philo.h
SRCS	=	philo.c \
			philo_parse.c \
			philo_list.c \
			philo_time.c \
			philo_start.c \
			philo_exit.c \
			utils.c
OBJS	:=	$(SRCS:.c=.o)
OBJ_DIR	=	objs/

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJS))
	@$(CC) $(LDFLAGS) -o $@ $^ $(CFLAGS)
	@echo "philo has been created"

$(OBJ_DIR)%.o: %.c $(INCS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)
	@echo "objs has been removed"

fclean: clean
	@rm -f $(NAME)
	@echo "philo has been removed"

re: fclean all

.PHONY: all clean fclean re
