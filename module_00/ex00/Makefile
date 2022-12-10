# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 13:37:09 by elraira-          #+#    #+#              #
#    Updated: 2022/12/10 13:48:02 by elraira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name the executable
NAME		=	megaphone

# compiler
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

# commands
RM			=	rm -f

# paths
OBJ_PATH	=	./obj/

SRCS		=	megaphone.cpp
OBJS		=	$(SRCS:%.cpp=%.o)

all:		$(NAME)

$(NAME):	$(addprefix $(OBJ_PATH), $(OBJS))
	$(CC) $(CFLAGS) -o $(NAME) $(addprefix $(OBJ_PATH), $(OBJS))

$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(addprefix $(OBJ_PATH), $(OBJS))
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
