# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/26 17:37:04 by hlin          #+#    #+#                  #
#    Updated: 2022/05/26 17:37:05 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := forms
INCS := Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
SRCS :=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

FLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

OBJS_DIR := obj/

OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

FILE_OUT = *_shrubbery

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
	@for i in $(FILE_OUT); do find . -name "$$i" -delete; done
	@echo "Object files has been removed.\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(NAME) executable has been removed.\n"

re: fclean all

.PHONY: all clean fclean re
