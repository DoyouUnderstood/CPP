CC = g++

CFLAGS = -Wall -Werror -Wextra -std=c++98

TARGET = megaphone

all: $(TARGET)

$(TARGET): megaphone.cpp
	$(CC) $(CFLAGS) megaphone.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
