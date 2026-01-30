# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mahkilic <mahkilic@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2026/01/31 00:59:09 by mahkilic      #+#    #+#                  #
#    Updated: 2026/01/31 00:59:09 by mahkilic      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= megaphone
CC				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++11
SRCS			= megaphone.cpp
OBJS			= $(SRCS:%.cpp=%.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
	@ echo "$(NAME) compiling..."
	@ $(CC) $^ $(CPPFLAGS) -o $(NAME)
	@ echo "$(NAME) made!"
	
$(OBJS)%.o:$(SRCS)%.cpp
	@ $(CC) $(CPPFLAGS) -c $< -o $@

clean		: 
	@ rm -rf $(OBJS)

fclean		: clean
	@ rm -f $(NAME)
	@ echo " $(NAME) fcleaned!"

re			: fclean all

.PHONY: all clean fclean re