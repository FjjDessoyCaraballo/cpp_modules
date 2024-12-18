NAME			=	type

COMP			=	c++
FLAGS			=	-Werror -Wextra -Wall

SRC_DIR			=	src
OBJ_DIR			=	obj
INC_DIR			=	inc

SRC				=	$(SRC_DIR)/main.cpp\
					$(SRC_DIR)/Base.cpp\
					$(SRC_DIR)/A.cpp\
					$(SRC_DIR)/B.cpp\
					$(SRC_DIR)/C.cpp\

OBJ				=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMP) $(FLAGS) -o $@ $^
	@echo "Getting your stuff nice and tidy: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(COMP) $(FLAGS) -I$(INC_DIR) -c $< -o $@

clean: 
	@rm -rf $(OBJ_DIR)
	@echo "Removing objects..."

fclean: clean
	@rm -rf $(NAME)
	@echo "Removing executable: $(NAME)"

re: fclean all

.PHONY: all clean fclean re