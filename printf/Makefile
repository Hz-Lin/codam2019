# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <marvin@codam.nl>                       +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/10 11:22:31 by hlin          #+#    #+#                  #
#    Updated: 2019/12/10 11:22:32 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC = src/ft_printf.c src/format_parser.c

OBJ = $(SRC:.c=.o)

INCLUDE = includes/ft_printf.h libft/libft.h

LIBFT = libft

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make bonus -C $(LIBFT)
	cp	libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I.

clean:
	/bin/rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
