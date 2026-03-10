# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/03/09 23:55:14 by mahkilic      #+#    #+#                  #
#    Updated: 2026/03/09 23:55:14 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= PmergeMe
CC				= c++
CPPFLAGS		= -Wall -Wextra -Werror

SRCS			=	main.cpp \
					PmergeMe.cpp

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