# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <marvin@codam.nl>                       +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 13:39:18 by hlin          #+#    #+#                  #
#    Updated: 2019/10/28 13:58:07 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c main.c

OBJ = $(SRC:.c=.o)

INCLUDES = includes/ 

all: $(NAME)

$(NAME): $(SRCS) libft.h
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean:
	/bin/rm -f $(NAME)

re: fclean all
