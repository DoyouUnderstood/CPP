CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = identify_real_type

SRC = main.cpp generate.cpp identify.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
