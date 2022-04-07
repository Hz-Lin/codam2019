# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/08 10:44:05 by hlin          #+#    #+#                  #
#    Updated: 2022/03/23 13:18:19 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := harl

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

INCS := Harl.hpp

SRCS := main.cpp Harl.cpp

OBJS_DIR := obj/

OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.cpp $(INCS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re