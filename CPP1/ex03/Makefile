CC := g++
CFLAGS := -std=c++11 -Wall -Wextra -pedantic

TARGET := ex03

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	@echo "Linking..."
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Build complete!"

%.o: %.cpp
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	$(RM) $(OBJS) $(TARGET)
	@echo "Clean complete!"

.PHONY: clean
