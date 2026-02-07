# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/02/07 19:06:20 by mahkilic      #+#    #+#                  #
#    Updated: 2026/02/07 19:28:47 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= violence
CC				= c++
CPPFLAGS		= -Wall -Wextra -Werror

SRCS			= src/main.cpp src/Weapon.cpp src/HumanA.cpp src/HumanB.cpp
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
