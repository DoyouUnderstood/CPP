NAME		= RPN
TEST_NAME	= test_RPN

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp RPN.cpp
TEST_SRCS	= test_RPN.cpp RPN.cpp
OBJS		= $(SRCS:.cpp=.o)
TEST_OBJS	= $(TEST_SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

test:		$(TEST_OBJS)
			$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_OBJS)
			./$(TEST_NAME)

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS) $(TEST_OBJS)

fclean:		clean
			rm -f $(NAME) $(TEST_NAME)

re:			fclean all

.PHONY:		all clean fclean re test
