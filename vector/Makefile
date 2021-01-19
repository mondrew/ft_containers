# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mondrew <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 23:16:50 by mondrew           #+#    #+#              #
#    Updated: 2021/01/19 20:26:46 by mondrew          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS = 	./main.cpp

INCLUDES = ./
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

%.o: %.c
	@clang++ $(FLAGS) -I $(INCLUDES) -c $< -o $@
	@echo "Compiling... Please wait..."

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling ... Please wait..."
	@clang++ $(OBJS) -o $(NAME)
	@echo "Compilation successfully done!"

clean:
	@echo "Cleaning object files ..."
	@/bin/rm -f $(OBJS)
	@echo "Object files has been removed!"

fclean: clean
	@echo "Cleaning all ..."
	@/bin/rm -f $(NAME)
	@echo "Everything has been removed!"

re: fclean all
