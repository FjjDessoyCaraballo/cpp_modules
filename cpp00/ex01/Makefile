NAME		= 	pb

COMP 		= 	c++

COMPFLAGS	= 	-Wall -Wextra #-Werror

SRCDIR 		= 	src
OBJDIR 		= 	obj
SRCS 		=	$(SRCDIR)/PhoneBook.cpp\
	   			$(SRCDIR)/Contact.cpp\
				$(SRCDIR)/main.cpp\

OBJS 		=	$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(COMP) $(COMPFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	@$(COMP) $(COMPFLAGS) $(OBJS) -o $(NAME)
	@echo "getting your stuff nice and tidy"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "Removing objects"
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Removing $(NAME)"

re: fclean all