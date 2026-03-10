# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/03/09 21:40:58 by mahkilic      #+#    #+#                  #
#    Updated: 2026/03/09 21:40:58 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= RPN
CC				= c++
CPPFLAGS		= -Wall -Wextra -Werror

SRCS			=	main.cpp \
					RPN.cpp

OBJDIR			= obj
OBJS			= $(SRCS:%.cpp=$(OBJDIR)/%.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
	@ echo "$(NAME) compiling..."
	@ $(CC) $^ $(CPPFLAGS) -o $(NAME)
	@ echo "$(NAME) made!"

$(OBJDIR):
	@ mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@ $(CC) $(CPPFLAGS) -c $< -o $@

clean		:
	@ rm -rf $(OBJDIR)

fclean		: clean
	@ rm -f $(NAME)

re			: fclean all

.PHONY: all clean fclean re
