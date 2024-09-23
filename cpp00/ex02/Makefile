NAME = bank

COMP = c++

COMPFLAGS = -Wall -Wextra #-Werror

SRCDIR = src
OBJDIR = obj
SRCS = $(SRCDIR)/tests.cpp\
	   $(SRCDIR)/Account.cpp\

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