# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/20 22:33:23 by hlin          #+#    #+#                  #
#    Updated: 2022/06/20 22:33:25 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := mutantstack
INCS := MutantStack.hpp
SRCS :=	main.cpp

FLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

OBJS_DIR := obj/

OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@c++ -o $@ $^
	@echo "$(NAME) executable has been created.\n"

$(OBJS_DIR)%.o: %.cpp $(INCS)
	@mkdir -p $(OBJS_DIR)
	@c++ -c $(FLAGS) -o $@ $<

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf $(OBJS_DIR)
	@echo "Object files has been removed.\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(NAME) executable has been removed.\n"

re: fclean all

.PHONY: all clean fclean re
