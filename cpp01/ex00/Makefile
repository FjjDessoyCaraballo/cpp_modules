NAME = zombie

COMP = c++

COMPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

SRCDIR = src
OBJDIR = obj
SRCS = $(SRCDIR)/main.cpp\
	   $(SRCDIR)/Zombie.cpp\
	   $(SRCDIR)/newZombie.cpp\
	   $(SRCDIR)/randomChump.cpp\

OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(COMP) $(COMPFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	@$(COMP) $(COMPFLAGS) $(OBJS) -o $(NAME)
	@echo "getting your stuff nice and tidy $(NAME)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
fclean: clean
	@rm -f $(NAME)
	@echo "Removing $(NAME)"

re: fclean all

.PHONY: all clean re fclean