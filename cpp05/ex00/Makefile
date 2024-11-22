NAME		=	bureaucrat

COMP		=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++11

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	inc

SRC			=	$(SRC_DIR)/main.cpp\
				$(SRC_DIR)/Bureaucrat.cpp

OBJ 		=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): $(OBJ)
	@$(COMP) $(FLAGS) -o $@ $^
	@echo "Getting your stuff nice and tidy: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(COMP) $(FLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all