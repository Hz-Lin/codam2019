# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/22 22:44:45 by hlin          #+#    #+#                  #
#    Updated: 2022/03/23 13:18:43 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := GlobalBankstersUnited

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

INCLUDES := Account.hpp

SRCS := tests.cpp Account.cpp

OBJS_DIR := obj/

OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.cpp $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all