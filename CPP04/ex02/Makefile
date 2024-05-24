CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98
LDFLAGS =

SRCS = main.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = polymorphism

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
