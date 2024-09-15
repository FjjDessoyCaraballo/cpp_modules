NAME		= megaphone
SRCDIR		= .
OBJDIR		= obj
INCLUDES	= .

SRC		= megaphone.cpp

#COMPILER
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++11

all: $(NAME)

$(NAME): $(SRCDIR)/$(SRC)
	@echo "getting your stuff nice and tidy $@"
	@$(CC) $(CFLAGS) -o $@ $^

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re