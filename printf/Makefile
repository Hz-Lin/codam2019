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

SRC = main.c src/ft_printf.c

OBJ = $(SRC:.c=.o)

INCLUDE = includes/ft_printf.h libft/libft.h

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(NAME) $(OBJBONUS)
	ar rcs $(NAME) $(OBJBONUS)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I.

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJBONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
