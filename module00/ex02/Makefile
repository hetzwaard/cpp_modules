# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2026/02/06 14:37:53 by mahkilic      #+#    #+#                  #
#    Updated: 2026/02/06 14:37:53 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	account
CC				=	c++
CPPFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS		+=	-Wno-deprecated-declarations

SRCS			= 	src/Account.cpp src/tests.cpp
OBJDIR			= obj
OBJS			= $(SRCS:src/%.cpp=$(OBJDIR)/%.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
	@ echo "$(NAME) compiling..."
	@ $(CC) $^ $(CPPFLAGS) -o $(NAME)
	@ echo "$(NAME) made!"
	
$(OBJDIR):
	@ mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	@ $(CC) $(CPPFLAGS) -c $< -o $@

clean		: 
	@ rm -rf $(OBJDIR)

fclean		: clean
	@ rm -f $(NAME)

re			: fclean all

.PHONY: all clean fclean re