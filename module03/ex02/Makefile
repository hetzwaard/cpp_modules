# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/02/12 20:29:52 by mahkilic      #+#    #+#                  #
#    Updated: 2026/02/13 14:40:31 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= fragtrap
CC				= c++
CPPFLAGS		= -Wall -Wextra -Werror

SRCS			= src/main.cpp src/ClapTrap.cpp src/ScavTrap.cpp src/FragTrap.cpp
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
