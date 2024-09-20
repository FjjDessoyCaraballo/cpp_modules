NAME		=	bank

COMPILER	=	c++
COMPFLAGS	=	-Wall -Wextra -Werror

SRCDIR		=	src
OBJDIR		=	obj
SRCS		=	$(SRCDIR)/Accounnt.cpp\
				$(SRCDIR)/tests.cpp\

OBJS 		= 	$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(COMPILER) $(COMPFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	@$(COMPILER) $(COMPFLAGS) $(OBJS) -o $(NAME)
	@echo "getting your stuff nice and tidy"

$(OBJDIR)
	@mkdir -p (OBJDIR)

clean:
	@echo "Removing objects"
	@rm -f (OBJS)
	@rm -rf (OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Removing $(NAME)"

re: fclean all

.PHONY: all clean fclean re