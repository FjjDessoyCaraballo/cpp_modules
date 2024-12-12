NAME		=	convert

COMP		=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++11 -fsanitize=address

SRC_DIR		=	src
INC_DIR		=	inc
OBJ_DIR		=	obj

SRC			=	$(SRC_DIR)/main.cpp\
				$(SRC_DIR)/ScalarConverter.cpp\

OBJ			=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMP) $(FLAGS) -o $@ $^
	@echo "Getting your stuff nice and tidy: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(COMP) $(FLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Removing objects"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_ASAN)
	@echo "Removing executable $(NAME)"

re: fclean all

.PHONY: all clean fclean re