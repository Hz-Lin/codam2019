# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/09 11:48:22 by hlin          #+#    #+#                  #
#    Updated: 2022/03/23 13:18:01 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := phonebook

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

INCLUDES := Contact.hpp PhoneBook.hpp

SRCS := Contact.cpp PhoneBook.cpp main.cpp

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