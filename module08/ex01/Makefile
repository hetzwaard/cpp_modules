# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/03/04 09:20:13 by mahkilic      #+#    #+#                  #
#    Updated: 2026/03/04 09:39:55 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= span
CC				= c++
CPPFLAGS		= -Wall -Wextra -Werror

SRCS			=	main.cpp \
					Span.cpp

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
