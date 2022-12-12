# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 13:37:09 by elraira-          #+#    #+#              #
#    Updated: 2022/12/12 11:54:17 by elraira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable
NAME		=	megaphone

# compiler and flags to use when compiling the project (C++98)
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

# commands to remove files and folders
RM			=	rm -f

# path to the object files
OBJ_PATH	=	./obj/

# source files
SRCS		=	megaphone.cpp
OBJS		=	$(SRCS:%.cpp=%.o)

# rules
all:		$(NAME)

# add folder prefix to object files and compile
$(NAME):	$(addprefix $(OBJ_PATH), $(OBJS))
	$(CC) $(CFLAGS) -o $(NAME) $(addprefix $(OBJ_PATH), $(OBJS))

# compile source files to object files, creating the folder if necessary
$(OBJ_PATH)%.o: %.cpp
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(addprefix $(OBJ_PATH), $(OBJS))
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME)

re: fclean all

# phony avoids conflicts with files named clean, fclean, re, etc.
.PHONY: all clean fclean re
