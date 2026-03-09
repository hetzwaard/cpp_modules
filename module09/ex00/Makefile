# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/03/05 19:10:31 by mahkilic      #+#    #+#                  #
#    Updated: 2026/03/05 19:29:20 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= btc
CC				= c++
CPPFLAGS		= -Wall -Wextra -Werror

SRCS			=	main.cpp \
					BitcoinExchange.cpp

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
