NAME			=	easyfind

SRC_DIR			=	src
INC_DIR			=	inc
OBJ_DIR			=	obj

COMP			=	c++
FLAGS			=	-Wall -Wextra -Werror -std=c++11 -I$(INC_DIR)

SRC				=	$(SRC_DIR)/main.cpp

OBJ				=	$(SRC: $(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMP) $(FLAGS) -o $@ $^ 
	@echo "Getting your stuff nice and tidy: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(COMP) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Removing objects"

fclean: clean
	@rm -rf $(NAME)
	@echo "Removing executable: $(NAME)"

re: fclean all

.PHONY: all clean fclean re
