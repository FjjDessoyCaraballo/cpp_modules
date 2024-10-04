NAME	= claptrap

COMP	= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98

SRCDIR	= src
OBJDIR	= obj
SRCS 	= 	$(SRCDIR)/main.cpp\
			$(SRCDIR)/ClapTrap.cpp

OBJS	= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCDIR))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(COMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	@$(COMP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "getting your stuff nice and tidy: $(NAME)"

$(OBDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -r $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Removing $(NAME)

re: fclean all

.PHONY: re all clean fclean
