# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsalaman <dsalaman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 13:39:18 by hlin          #+#    #+#                  #
#    Updated: 2021/04/28 18:58:10 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC_LIBFT = ft_toupper.c ft_tolower.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_isdigit.c ft_isspace.c \
ft_memset.c ft_bzero.c ft_calloc.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_memalloc.c  \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_atoi.c ft_itoa.c ft_atoss.c \
ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
ft_strcmp.c ft_strncmp.c ft_strequ.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_strmapi.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
get_next_line_utils.c get_next_line.c

SRC_PRINTF = ft_printf.c parsers_utilites.c parsers.c output.c \
convert_cs.c convert_pointer.c convert_number.c convert_number_utilities.c

LIBFT_PATH = ./srcs/
PRINTF_PATH = ./ft_printf/

SRC = $(addprefix $(LIBFT_PATH), $(SRC_LIBFT)) \
	$(addprefix $(PRINTF_PATH), $(SRC_PRINTF))

OBJ = $(SRC:.c=.o)

INCLUDE = srcs/libft.h ft_printf/ft_printf.h

.PHONY: clean fclean all re bonus

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(all)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I.

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
