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

FLAGS = -Wall -Werror -Wextra

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

INCLUDE = libft.h

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(OBJBONUS)
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
