NAME				=	RPN

CC					=	c++
FLAGS				=	-Wall -Wextra -Werror -std=c++11

SRC_DIR				=	src
OBJ_DIR				=	obj

SRC					=	$(SRC_DIR)/main.cpp\
						$(SRC_DIR)/rpn.cpp

OBJ 				=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "Getting your stuff nice and tidy: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "Removing object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "Removing executable"

re: fclean all

.PHONY: all clean fclean re