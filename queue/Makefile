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
	@/bin/rm -f $(OBJS) *.o
	@echo "Object files has been removed!"

fclean: clean
	@echo "Cleaning all ..."
	@/bin/rm -f $(NAME)
	@echo "Everything has been removed!"

re: fclean all
