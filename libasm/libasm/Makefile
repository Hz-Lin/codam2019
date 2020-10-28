# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 23:36:29 by hlin          #+#    #+#                  #
#    Updated: 2020/10/28 22:21:40 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

SRC_BONUS = ft_strlen.s

ifdef WITH_BONUS
OBJ = $(SRC:.s=.o) $(SRC_BONUS:.s=.o)
else
OBJ = $(SRC:.s=.o)
endif

NASM = nasm -f macho64

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\nCreating the library\n"
	ar rc $@ $^
	ranlib $@

%.o: %.s
	@echo "\nCompiling:\n"
	$(NASM) $<

bonus: $(SRC_BONUS)
	@echo "\nCompiling bonus\n"
	$(MAKE) WITH_BONUS=1 all

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus