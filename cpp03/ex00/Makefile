NAME	= claptrap

COMP	= c++
FLAGS	= -Wall -Werror -Wextra -std=c++11

SRCDIR	= src
OBJDIR	= obj
SRCS 	= 	$(SRCDIR)/main.cpp\
			$(SRCDIR)/ClapTrap.cpp\

OBJS	= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	@$(COMP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "getting your stuff nice and tidy: $(NAME)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "Removing $(NAME)"

re: fclean all

.PHONY: re all clean fclean