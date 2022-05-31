# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/26 17:27:41 by hlin          #+#    #+#                  #
#    Updated: 2022/05/26 17:27:42 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := form
INCS := Bureaucrat.hpp Form.hpp
SRCS :=	main.cpp Bureaucrat.cpp Form.cpp

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
