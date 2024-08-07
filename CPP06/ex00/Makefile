# Makefile
NAME = scalar_converter
CC = g++
CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp ScalarConvert.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
