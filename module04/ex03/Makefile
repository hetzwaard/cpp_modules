# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/02/16 16:29:54 by mahkilic      #+#    #+#                  #
#    Updated: 2026/02/16 17:19:18 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= interface
CC				= c++
CPPFLAGS		= -Wall -Wextra -Werror

SRCS			= src/main.cpp src/AMateria.cpp src/Ice.cpp src/Cure.cpp \
				src/Character.cpp src/MateriaSource.cpp src/ICharacter.cpp \
				src/IMateriaSource.cpp
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
