NAME		=	animal

COMP		=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++11

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	inc

SRC			=	$(SRC_DIR)/main.cpp\
				$(SRC_DIR)/Animal.cpp\
				$(SRC_DIR)/Dog.cpp\
				$(SRC_DIR)/Cat.cpp\

OBJS		=	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(COMP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "getting your stuff nice and tidy: $(NAME)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "removing objects"

fclean: clean
	@rm -rf $(NAME)
	@echo "removing executable $(NAME)"

re: fclean all

.PHONY: re all clean fclean