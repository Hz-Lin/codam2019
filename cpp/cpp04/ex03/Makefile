NAME := interface

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

OBJ_DIR := obj/
SRC_DIR := src/
INC_DIR := includes/

SRC := main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
SRC_PATH := $(addprefix $(SRC_DIR), $(SRC))
OBJ := $(SRC_PATH:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^
	@echo "$(NAME) executable has been created.\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $< -I$(INC_DIR)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "clean: object files has been removed."

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "fclean: executable file has been removed."

re: fclean all

.PHONY: all clean fclean re